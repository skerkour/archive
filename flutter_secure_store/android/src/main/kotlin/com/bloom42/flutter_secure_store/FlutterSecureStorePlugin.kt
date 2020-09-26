package com.bloom42.flutter_secure_store

import android.content.Context
import io.flutter.Log
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result
import io.flutter.plugin.common.PluginRegistry.Registrar


class FlutterSecureStorePlugin : MethodCallHandler {
  companion object {
    private const val FLUTTER_CHANNEL_NAME = "com.bloom42.flutter_secure_store"
    private const val LOG_TAG = "FlutterSecureStore"


    @JvmStatic
    fun registerWith(registrar: Registrar) {
      val channel = MethodChannel(registrar.messenger(), FLUTTER_CHANNEL_NAME)
      channel.setMethodCallHandler(FlutterSecureStorePlugin(registrar.context()))
    }
  }

  private val store: SecureStore

  @Throws(Exception::class)
  constructor(context: Context) {
    this.store = SecureStore(context)
  }


  override fun onMethodCall(call: MethodCall, result: Result) {
    try {
      when (call.method) {
        "set" -> set(call, result)
        "get" -> get(call, result)
        "keys" -> keys(result)
        "delete" -> delete(call, result)
        "deleteAll" -> deleteAll(result)
        "contains" -> contains(call, result)
        else -> result.notImplemented()
      }
    } catch (err: Exception) {
      result.error("Exception encountered", call.method, err);
    }
  }

  private fun set(call: MethodCall, result: Result) {
    Log.d(LOG_TAG, "set")
    val (key, value) = extractKeyValue(call)

    store.set(key, value)
    result.success(null)
  }

  private fun get(call: MethodCall, result: Result) {
    Log.d(LOG_TAG, "get")
    val key = extractKey(call)
    result.success(store.get(key))
  }

  private fun keys(result: Result) {
    Log.d(LOG_TAG, "keys")

    result.success(store.keys())
  }

  private fun delete(call: MethodCall, result: Result) {
    Log.d(LOG_TAG, "delete")
    val key = extractKey(call)

    store.delete(key)
    result.success(null)
  }

  private fun deleteAll(result: Result) {
    Log.d(LOG_TAG, "deleteAll")

    store.deleteAll()
    result.success(null)
  }

  private fun contains(call: MethodCall, result: Result) {
    Log.d(LOG_TAG, "contains")
    val key = extractKey(call)

    result.success(store.contains(key))
  }

  private fun extractKey(call: MethodCall): String {
    val arguments = call.arguments as Map<*, *>
    return arguments["key"] as String
  }

  private fun extractKeyValue(call: MethodCall): Pair<String, String> {
    val arguments = call.arguments as Map<*, *>
    val key = arguments["key"] as String
    val value = arguments["value"] as String
    return Pair(key, value)
  }
}
