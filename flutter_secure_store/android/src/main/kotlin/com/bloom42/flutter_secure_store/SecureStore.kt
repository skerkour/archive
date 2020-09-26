package com.bloom42.flutter_secure_store

import android.content.Context
import android.content.SharedPreferences
import android.os.Build
import com.bloom42.flutter_secure_store.crypto.KeyStoreHelper
import java.lang.Exception


class SecureStore {
  companion object {
    const val SHARED_PREFERENCES_NAME = "FlutterSecureStore"
  }

  private val sharedPreferences: SharedPreferences

  constructor(context: Context){
    this.sharedPreferences = context.getSharedPreferences(SHARED_PREFERENCES_NAME, Context.MODE_PRIVATE)
  }


  fun set(key: String, value: String) {
    if (Build.VERSION.SDK_INT < Build.VERSION_CODES.M) {
      throw Exception("Android version is too low (M is required");
    } else {
      val editor = sharedPreferences.edit()
      // we prepend the key to assure authenticity of the key/value pair
      // (ie an attack who have access to the shared preference file can't swap keys/values)
      val cipherText = KeyStoreHelper.encryptKeyValue(key, value)
      editor.putString(key, cipherText)
      editor.commit()
    }
  }

  fun get(key: String): String? {
    if (Build.VERSION.SDK_INT < Build.VERSION_CODES.M) {
      throw Exception("Android version is too low (M is required");
    } else {
      val ciphertext = sharedPreferences.getString(key, null)
      ciphertext ?: return null

      val plaintext = KeyStoreHelper.decryptKeyValue(key, ciphertext)
      return String(plaintext)
    }
  }

  fun delete(key: String) {
    val editor = sharedPreferences.edit()
    editor.remove(key)
    editor.commit()
  }

  fun deleteAll() {
    val editor = sharedPreferences.edit()
    editor.clear()
    editor.commit()
  }

  fun contains(key: String): Boolean {
    return sharedPreferences.contains(key)
  }

  fun keys(): List<String> {
    val prefs = sharedPreferences.all
    return prefs.keys.toList()
  }
}