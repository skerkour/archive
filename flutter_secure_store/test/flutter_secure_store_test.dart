import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:flutter_secure_store/flutter_secure_store.dart';

void main() {
  const MethodChannel channel = MethodChannel(SecureStore.FLUTTER_CHANNEL_NAME);
  Map<String, dynamic> _keyStore = <String, dynamic>{};
  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      switch (methodCall.method) {
        case 'set':
          final String key = methodCall.arguments['key'];
          final String value = methodCall.arguments['value'];
          _keyStore[key] = value;
          return null;

        case 'get':
          final String key = methodCall.arguments['key'];
          return _keyStore[key];
          break;

        case 'contains':
          final String key = methodCall.arguments['key'];
          return _keyStore[key] != null;
          break;

        case 'keys':
          return _keyStore.keys.toList();
          break;

        case 'deleteAll':
          _keyStore = <String, dynamic>{};
          return null;
          break;

        case 'delete':
          final String key = methodCall.arguments['key'];
          _keyStore[key] = null;
          return null;
          break;
      }
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('String', () async {
    const String key = 'key1';
    const String expected = 'value11';

    await SecureStore.setString(key, expected);
    final String value = await SecureStore.getString(key);
    expect(value, expected);
  });

  test('int', () async {
    const String key = 'key1';
    const int expected = 42;

    await SecureStore.setInt(key, expected);
    final int value = await SecureStore.getInt(key);
    expect(value, expected);
  });

  test('double', () async {
    const String key = 'key1';
    const double expected = 42.42;

    await SecureStore.setDouble(key, expected);
    final double value = await SecureStore.getDouble(key);
    expect(value, expected);
  });

  test('bool', () async {
    const String key = 'key1';
    const bool expected = true;

    await SecureStore.setBool(key, expected);
    final bool value = await SecureStore.getBool(key);
    expect(value, expected);
  });

  test('get null bool', () async {
    const bool expected = null;

    final bool value = await SecureStore.getBool('invalidKey');
    expect(value, expected);
  });

  test('contains', () async {
    const String key = 'key1111';
    const bool expected = true;

    await SecureStore.setString(key, 'value');
    final bool contains = await SecureStore.contains(key);
    expect(
      contains,
      expected,
    );
  });

  test('contains (does not)', () async {
    const String key = 'key1111';
    const bool expected = false;

    await SecureStore.setString(key, 'value');
    final bool contains = await SecureStore.contains('invalidKey');
    expect(contains, expected);
  });

  test('keys', () async {
    const int expected = 2;

    final List<String> keys = await SecureStore.keys();
    expect(keys.length, expected);
  });

  test('delete', () async {
    const bool expected = false;
    const String key = 'key1111';
    const String value = 'value';

    await SecureStore.setString(key, value);
    await SecureStore.delete(key);
    final bool contains = await SecureStore.contains(key);
    expect(contains, expected);
  });

  test('deleteAll', () async {
    const int expected = 0;

    await SecureStore.deleteAll();
    final List<String> keys = await SecureStore.keys();
    expect(keys.length, expected);
  });
}
