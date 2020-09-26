import 'dart:async';

import 'package:flutter/services.dart';

class SecureStore {
  static const String FLUTTER_CHANNEL_NAME = 'com.bloom42.flutter_secure_store';
  static const MethodChannel _channel = MethodChannel(FLUTTER_CHANNEL_NAME);

  /// Saves an encrypted bool [value] in the SecureStore
  static Future<void> setBool(String key, bool value) {
    return setString(key, _boolToString(value));
  }

  /// Saves an encrypted double [value] in the SecureStore
  static Future<void> setDouble(String key, double value) {
    return setString(key, value.toString());
  }

  /// Saves an encrypted int [value] in the SecureStore
  static Future<void> setInt(String key, int value) {
    return setString(key, value.toString());
  }

  /// Saves an encrypted String [value] in the SecureStore
  static Future<void> setString(String key, String value) {
    return _channel
        .invokeMethod('set', <String, dynamic>{'key': key, 'value': value});
  }

  /// Reads a bool value from the SecureStore
  static Future<bool> getBool(String key) async {
    final String value = await getString(key);
    return value == null ? null : _boolFromString(value);
  }

  /// Reads a double value from the SecureStore
  static Future<double> getDouble(String key) async {
    final String value = await getString(key);
    return value == null ? null : double.parse(value);
  }

  /// Reads an int value from the SecureStore
  static Future<int> getInt(String key) async {
    final String value = await getString(key);
    return value == null ? null : int.parse(value);
  }

  /// Reads a String value from the SecureStore
  static Future<String> getString(String key) {
    return _channel.invokeMethod('get', <String, dynamic>{'key': key});
  }

  /// Removes an entry from the SecureStore
  static Future<void> delete(String key) {
    return _channel.invokeMethod('delete', <String, dynamic>{'key': key});
  }

  /// Removes all entries from the SecureStore
  static Future<void> deleteAll() {
    return _channel.invokeMethod('deleteAll');
  }

  /// Returns true if the SecureStore contains the given [key].
  static Future<bool> contains(String key) {
    return _channel.invokeMethod('contains', <String, dynamic>{'key': key});
  }

  /// Returns all keys in the SecureStore.
  static Future<List<String>> keys() async {
    return (await _channel.invokeMethod<List<dynamic>>('keys')).cast<String>();
  }

  static bool _boolFromString(String val) {
    if (val == '1') {
      return true;
    } else if (val == '2') {
      return false;
    } else {
      throw const FormatException('value cannot be parsed from String to bool');
    }
  }

  static String _boolToString(bool val) {
    if (val == true) {
      return '1';
    } else {
      return '2';
    }
  }
}
