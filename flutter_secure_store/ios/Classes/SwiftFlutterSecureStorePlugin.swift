import Flutter

enum MyFlutterErrorCode {
    static let keychainError = "KEYCHAIN_ERROR"
}

let FLUTTER_CHANNEL_NAME = "com.bloom42.flutter_secure_store"

public class SwiftFlutterSecureStorePlugin: NSObject, FlutterPlugin {
    public static func register(with registrar: FlutterPluginRegistrar) {
        let channel = FlutterMethodChannel(name: FLUTTER_CHANNEL_NAME, binaryMessenger: registrar.messenger())
        let instance = SwiftFlutterSecureStorePlugin()
        registrar.addMethodCallDelegate(instance, channel: channel)
    }
    
    public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        switch call.method {
        case "set":
            set(call, result)
        case "get":
            get(call, result)
        case "keys":
            keys(result)
        case "delete":
            delete(call, result)
        case "deleteAll":
            deleteAll(result)
        case "contains":
            contains(call, result)
        default:
            result(FlutterMethodNotImplemented)
        }
    }
    
    private func set(_ call: FlutterMethodCall, _ result: FlutterResult) {
        let (key, value) = extractKeyValue(call)

        let success: Bool = KeychainWrapper.standard.set(value, forKey: key)
        if (success) {
            result(nil)
        } else {
            result(FlutterError(
                code: MyFlutterErrorCode.keychainError,
                message: "error setting item in Keychain",
                details: nil
            ))
        }
    }
    
    private func get(_ call: FlutterMethodCall, _ result: FlutterResult) {
        let key = extractKey(call)

        result(KeychainWrapper.standard.string(forKey: key))
    }
    
    private func keys(_ result: FlutterResult) {
        let keys = KeychainWrapper.standard.allKeys()
        result(Array(keys))
    }
    
    private func delete(_ call: FlutterMethodCall, _ result: FlutterResult) {
        let key = extractKey(call)
        
        let success: Bool = KeychainWrapper.standard.removeObject(forKey: key)
        if (success) {
            result(nil)
        } else {
            result(FlutterError(
                code: MyFlutterErrorCode.keychainError,
                message: "error deleting item from Keychain",
                details: nil
            ))
        }
    }
    
    private func deleteAll(_ result: FlutterResult) {
        let success: Bool = KeychainWrapper.standard.removeAllKeys()
        if (success) {
            result(nil)
        } else {
            result(FlutterError(
                code: MyFlutterErrorCode.keychainError,
                message: "error deleting all items from Keychain",
                details: nil
            ))
        }
    }
    
    private func contains(_ call: FlutterMethodCall, _ result: FlutterResult) {
        let key = extractKey(call)
        
        let contains: Bool = KeychainWrapper.standard.hasValue(forKey: key)
        result(contains)
    }
    
    private func extractKey(_ call: FlutterMethodCall) -> String {
        let arguments = call.arguments as! [String: Any]
        return arguments["key"] as! String
    }
    
    private func extractKeyValue(_ call: FlutterMethodCall) -> (String, String) {
        let arguments = call.arguments as! [String: Any]
        return (arguments["key"] as! String, arguments["value"] as! String)
    }
}
