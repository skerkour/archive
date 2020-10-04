package com.bloom42.bloom

import android.Manifest
import android.annotation.SuppressLint
import android.app.Activity
import android.os.Bundle
import android.support.v4.widget.SwipeRefreshLayout
import android.support.v7.app.AppCompatActivity
import android.view.KeyEvent
import android.content.Intent
import android.net.Uri
import android.support.v4.app.ActivityCompat.startActivityForResult
import android.widget.Toast
import android.app.DownloadManager
import android.content.Context
import android.os.Environment
import android.os.Environment.DIRECTORY_DOWNLOADS
import android.webkit.*
import android.support.v4.app.ActivityCompat
import android.content.DialogInterface
import android.content.pm.PackageManager
import android.graphics.Bitmap
import android.os.Build
import android.support.v7.app.AlertDialog
import android.support.v4.app.ActivityCompat.startActivityForResult
import android.util.Log
import android.webkit.ValueCallback
import android.support.v4.app.ActivityCompat.startActivityForResult
import android.webkit.WebView








class MainActivity : AppCompatActivity() {

    private lateinit var webView: WebView
    private var mUploadMessage: ValueCallback<Array<Uri>>? = null
    private val FILECHOOSER_RESULTCODE = 1
    private val MY_PERMISSION_REQUEST_CODE = 123
    private lateinit var mActivity: AppCompatActivity


    @SuppressLint("SetJavaScriptEnabled")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        mActivity = this@MainActivity

        webView = findViewById(R.id.main_webview)
        setupWebView()

//        swipe = findViewById(R.id.swiperefresh)
//        swipe.setOnRefreshListener {
//            webView.reload()
//        }
    }

    @SuppressLint("SetJavaScriptEnabled")
    private fun setupWebView() {
        if (BuildConfig.DEBUG) {
            WebView.setWebContentsDebuggingEnabled(true)
        }

        webView.settings.javaScriptEnabled = true
        webView.settings.displayZoomControls = false
        webView.settings.domStorageEnabled = true
        webView.settings.allowFileAccess = true
        webView.settings.allowContentAccess = true
        webView.loadUrl("https://bloom.sh/register")
        webView.webViewClient = object : WebViewClient() {
//            override fun onPageFinished(view: WebView, url: String) {
//                swipe.isRefreshing = false
//            }
        }

        // handle downloads listener
        webView.setDownloadListener { url, _, contentDisposition, mimeType, _ ->
            if (!haveWritePermission()) {
                checkPermission()
            } else {
                val request = DownloadManager.Request(Uri.parse(url))
                request.allowScanningByMediaScanner()
                request.setNotificationVisibility(DownloadManager.Request.VISIBILITY_VISIBLE_NOTIFY_COMPLETED) // Notify client once download is completed

                val fileName = URLUtil.guessFileName(url, contentDisposition, mimeType);
                request.setDestinationInExternalPublicDir(Environment.DIRECTORY_DOWNLOADS, fileName)
                val dm = getSystemService(Context.DOWNLOAD_SERVICE) as DownloadManager
                dm.enqueue(request)
                Toast.makeText(
                    applicationContext, "Downloading File", //To notify the Client that the file is being downloaded
                    Toast.LENGTH_LONG
                ).show()
            }
        }

        webView.webChromeClient = object:WebChromeClient() {
            override fun onShowFileChooser(webView:WebView, filePathCallback:ValueCallback<Array<Uri>>, fileChooserParams:FileChooserParams):Boolean {
                mUploadMessage = filePathCallback
                val intent = Intent(Intent.ACTION_GET_CONTENT)
                intent.type = "*/*"
                intent.addCategory(Intent.CATEGORY_OPENABLE);
                startActivityForResult(intent, FILECHOOSER_RESULTCODE)
                return true
            }
        }
    }

    override fun onKeyDown(keyCode: Int, event: KeyEvent): Boolean {
        if (event.action == KeyEvent.ACTION_DOWN) {
            when (keyCode) {
                KeyEvent.KEYCODE_BACK -> {
                    if (webView.canGoBack()) {
                        webView.goBack()
                    } else {
                        finish()
                    }
                    return true
                }
            }

        }
        return super.onKeyDown(keyCode, event)
    }

    override fun onActivityResult(
        requestCode: Int, resultCode: Int,
        intent: Intent?
    ) {
        if (requestCode == FILECHOOSER_RESULTCODE) {
            if (null == mUploadMessage)
                return
            val result: Array<Uri> = if (intent == null || resultCode != Activity.RESULT_OK)
                arrayOf()
            else
                arrayOf(intent.data)
            mUploadMessage?.onReceiveValue(result)
            mUploadMessage = null
        }
    }

    protected fun checkPermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            if (checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
                if (shouldShowRequestPermissionRationale(Manifest.permission.WRITE_EXTERNAL_STORAGE)) {
                    // show an alert dialog
                    val builder = AlertDialog.Builder(mActivity)
                    builder.setMessage("Write external storage permission is required to download files from Drive.")
                    builder.setTitle("Allow storage permission")
                    builder.setPositiveButton("OK", DialogInterface.OnClickListener { dialogInterface, i ->
                        ActivityCompat.requestPermissions(
                            mActivity,
                            arrayOf(Manifest.permission.WRITE_EXTERNAL_STORAGE),
                            MY_PERMISSION_REQUEST_CODE
                        )
                    })
                    builder.setNeutralButton("Cancel", null)
                    val dialog = builder.create()
                    dialog.show()
                } else {
                    // Request permission
                    ActivityCompat.requestPermissions(
                        mActivity,
                        arrayOf(Manifest.permission.WRITE_EXTERNAL_STORAGE),
                        MY_PERMISSION_REQUEST_CODE
                    )
                }
            } else {
                // Permission already granted
            }
        }
    }

    private fun haveWritePermission(): Boolean {
        return if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED
        } else {
            true
        }
    }

    override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<String>, grantResults: IntArray) {
        when (requestCode) {
            MY_PERMISSION_REQUEST_CODE -> {
                if (grantResults.size > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    // Permission granted
                } else {
                    // Permission denied
                }
            }
        }
    }
}