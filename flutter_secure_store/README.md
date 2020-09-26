<p align="center">
  <h3 align="center">flutter_secure_store</h3>
  <p align="center">A simple and secure persistent key-value store for flutter (Android, IOS)</p>
</p>


--------

# WIP, DO NOT USE IN PRODUCTION

*flutter_secure_store* is a simple to use and secure key-value value store for Flutter.
It can be used to securely store API keys, user preferences...

1. [Usage](#usage)
2. [Installation](#Installation)
3. [Contributing](#contributing)
4. [Licensing](#licensing)
5. [Security](#security)

--------

## Usage

```dart
// Available methods
Future<void> setBool(String key, bool value)
Future<void> setDouble(String key, double value)
Future<void> setInt(String key, int value)
Future<void> setString(String key, String value)

Future<bool> getBool(String key)
Future<double> getDouble(String key)
Future<int> getInt(String key)
Future<String> getString(String key)

Future<void> delete(String key)
Future<void> deleteAll()
Future<bool> contains(String key)
Future<List<String>> keys()

// Usage
// all methods of SecureStore are static
await SecureStore.setString('last_launch',  DateTime.now().toString());
final String value = await SecureStore.getString('last_launch');
```

## Installation

### Flutter

#### Using Git (recommended)
```yaml
# ...
dependencies:
  # ...
  flutter_secure_store:
    git:
      url: https://gitlab.com/bloom42/libs/flutter_secure_store.git
      ref: master
```

#### Using Pub

[https://pub.dev/packages/flutter_secure_store](https://pub.dev/packages/flutter_secure_store)


### Android

In `[project]/android/app/build.gradle` verify that `minSdkVersion` is >= `18`.

```graddle
android {
    // ...

    defaultConfig {
        // ...
        minSdkVersion 18
        // ...
    }
}
```

### iOS

Nothing to do.

## Internals

### IOS

[Keychain](https://developer.apple.com/documentation/security/keychain_services) is used for iOS.

### Android

* For devices Android >= 23: `AES/GCM/NoPadding` encryption using [Android KeyStore](https://developer.android.com/training/articles/keystore) with a key size of 256 bits (using secure hardware when available).
* For devices `18` <= Android < `23`: `AES/GCM/NoPadding` secret key (256 bits) is encrypted with `RSA 4096`, the latter key being stored in [Android KeyStore](https://developer.android.com/training/articles/keystore).




## Licensing

See `LICENSE.txt` and [https://bloom.sh/licensing](https://bloom.sh/licensing)


## Security

If you found a security issue affecting this project, please do not open a public issue and refer to our
[dedicated security page](https://bloom.sh/security) instead. Thank you.


## Issues

### 18 <= Android < 23 support

depends on
https://github.com/google/tink/issues/226#issuecomment-517039047
and
https://issuetracker.google.com/issues/132325342
