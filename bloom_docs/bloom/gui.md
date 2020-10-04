See https://gitlab.com/z0mbie42/rust_gui_ecosystem_overview/

# Notes

`main.rs`
```rust
#![feature(link_args)]

// dynamic
// #![link_args="-Wl,-rpath /Users/user/Qt/5.13.0/clang_64/lib"]
// #![link_args="-Wl,-rpath /Users/user/Qt/5.13.0/clang_64/plugins/platforms"]
// #![link_args="-l Qt5Gui -l Qt5Widgets -l Qt5Core -l Qt5Quick -l Qt5Qml -l Qt5QuickControls2 -l Qt5Network"]


// static
// #![link_args="-fPIC -headerpad_max_install_names -arch x86_64 -Wl,-syslibroot,/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk -mmacosx-version-min=10.12 -Wl,-rpath,@executable_path/../Frameworks -l qmacstyle /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/lib/libz.tbd -lqcocoa -lcups -lQt5AccessibilitySupport -lQt5ThemeSupport -lQt5DBus -lQt5FontDatabaseSupport -lqtfreetype -lQt5GraphicsSupport -lQt5ClipboardSupport -lqgif -lqicns -lqico -lqjpeg -lqmacheif -lqmacjp2  -lqtga -lqtiff -lqwbmp -lqwebp /Users/user/QtStatic/plugins/qmltooling/libqmldbg_debugger.a /Users/user/QtStatic/plugins/qmltooling/libqmldbg_inspector.a /Users/user/QtStatic/plugins/qmltooling/libqmldbg_local.a /Users/user/QtStatic/plugins/qmltooling/libqmldbg_messages.a /Users/user/QtStatic/plugins/qmltooling/libqmldbg_native.a /Users/user/QtStatic/plugins/qmltooling/libqmldbg_nativedebugger.a /Users/user/QtStatic/plugins/qmltooling/libqmldbg_preview.a /Users/user/QtStatic/plugins/qmltooling/libqmldbg_profiler.a /Users/user/QtStatic/plugins/qmltooling/libqmldbg_quickprofiler.a /Users/user/QtStatic/plugins/qmltooling/libqmldbg_server.a -lQt5PacketProtocol /Users/user/QtStatic/plugins/qmltooling/libqmldbg_tcp.a /Users/user/QtStatic/plugins/bearer/libqgenericbearer.a /Users/user/QtStatic/plugins/printsupport/libcocoaprintersupport.a -lQt5PrintSupport -lQt5Widgets -lz /Users/user/QtStatic/qml/QtQuick/Layouts/libqquicklayoutsplugin.a /Users/user/QtStatic/qml/QtQuick.2/libqtquick2plugin.a /Users/user/QtStatic/qml/QtQuick/Templates.2/libqtquicktemplates2plugin.a /Users/user/QtStatic/qml/QtQuick/Controls.2/libqtquickcontrols2plugin.a /Users/user/QtStatic/qml/QtQuick/Controls.2/Fusion/libqtquickcontrols2fusionstyleplugin.a /Users/user/QtStatic/qml/QtQuick/Controls.2/Universal/libqtquickcontrols2universalstyleplugin.a /Users/user/QtStatic/qml/QtQuick/Controls.2/Material/libqtquickcontrols2materialstyleplugin.a /Users/user/QtStatic/qml/QtGraphicalEffects/private/libqtgraphicaleffectsprivate.a /Users/user/QtStatic/qml/QtQuick/Window.2/libwindowplugin.a /Users/user/QtStatic/qml/QtGraphicalEffects/libqtgraphicaleffectsplugin.a /Users/user/QtStatic/qml/QtQuick/Controls.2/Imagine/libqtquickcontrols2imaginestyleplugin.a -lQt5QuickControls2 -lQt5QuickTemplates2 -lQt5Quick -lQt5Gui -lqtlibpng -lqtharfbuzz -lQt5Qml -lQt5Network -lQt5Core -lm -lqtpcre2 /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.1/lib/darwin/libclang_rt.osx.a"]

use std::{
    ffi::CString,
    env,
    os::raw::{c_char, c_int},
};

mod interface;
mod implementation;

#[link(name = "qgrep", kind="static")]
extern "C" {
    fn main_cpp(app: *const c_char) -> c_int;
}

fn main() {
    let mut args = env::args();
    let app = CString::new(args.next().unwrap()).unwrap();
    unsafe {
        main_cpp(app.as_ptr());
    }
}
```
