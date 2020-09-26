#import "FlutterSecureStorePlugin.h"
#import <flutter_secure_store/flutter_secure_store-Swift.h>

@implementation FlutterSecureStorePlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftFlutterSecureStorePlugin registerWithRegistrar:registrar];
}
@end
