pub use serde::de::{Deserialize, IntoDeserializer};

// use crate::value::{List, Map, Value};

/// Construct a [`sane::Value`] from SANE syntax.
///
/// [`sane::Value`]: value/enum.Value.html
///
/// ```rust
/// #[macro_use]
/// extern crate sane;
///
/// fn main() {
///     let cargo_sane = sane! {
///         [package]
///         name = "sane"
///         version = "0.4.5"
///         authors = ["Alex Crichton <alex@alexcrichton.com>"]
///
///         [badges]
///         travis-ci = { repository = "alexcrichton/sane-rs" }
///
///         [dependencies]
///         serde = "1.0"
///
///         [dev-dependencies]
///         serde_derive = "1.0"
///         serde_json = "1.0"
///     };
///
///     println!("{:#?}", cargo_sane);
/// }
/// ```
#[macro_export]
macro_rules! sane {
    ($($sane:tt)+) => {{
        let map = $crate::value::Map::new();
        let mut root = $crate::Value::Map(map);
        sane_internal!(@toplevel root [] $($sane)+);
        root
    }};
}

// TT-muncher to parse SANE syntax into a sane::Value.
//
//    @toplevel -- Parse tokens outside of an inline map or inline list. In
//                 this state, `[map headers]` and `[[list headers]]` are
//                 allowed and `key = value` pairs are not separated by commas.
//
//    @topleveldatetime -- Helper to parse a Datetime from string and insert it
//                 into a map, continuing in the @toplevel state.
//
//    @path -- Turn a path segment into a string. Segments that look like idents
//                 are stringified, while quoted segments like `"cfg(windows)"`
//                 are not.
//
//    @value -- Parse the value part of a `key = value` pair, which may be a
//                 primitive or inline map or inline list.
//
//    @map -- Parse the contents of an inline map, returning them as a
//                 sane::Value::Map.
//
//    @mapdatetime -- Helper to parse a Datetime from string and insert it
//                 into a map, continuing in the @map state.
//
//    @list -- Parse the contents of an inline list, returning them as a
//                 sane::Value::List.
//
//    @listdatetime -- Helper to parse a Datetime from string and push it into
//                 an list, continuing in the @list state.
//
//    @trailingcomma -- Helper to append a comma to a sequence of tokens if the
//                 sequence is non-empty and does not already end in a trailing
//                 comma.
//
#[macro_export]
#[doc(hidden)]
macro_rules! sane_internal {
    // Base case, no elements remaining.
    (@toplevel $root:ident [$($path:tt)*]) => {};

    // Parse negative number `key = -value`.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = - $v:tt $($rest:tt)*) => {
        sane_internal!(@toplevel $root [$($path)*] $($($k)-+).+ = (-$v) $($rest)*);
    };

    // Parse positive number `key = +value`.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = + $v:tt $($rest:tt)*) => {
        sane_internal!(@toplevel $root [$($path)*] $($($k)-+).+ = ($v) $($rest)*);
    };

    // Parse offset datetime `key = 1979-05-27T00:32:00.999999-07:00`.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt . $frac:tt - $tzh:tt : $tzm:tt $($rest:tt)*) => {
        sane_internal!(@topleveldatetime $root [$($path)*] $($($k)-+).+ = ($yr - $mo - $dhr : $min : $sec . $frac - $tzh : $tzm) $($rest)*);
    };
    // Space instead of T.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt . $frac:tt - $tzh:tt : $tzm:tt $($rest:tt)*) => {
        sane_internal!(@topleveldatetime $root [$($path)*] $($($k)-+).+ = ($yr - $mo - $day T $hr : $min : $sec . $frac - $tzh : $tzm) $($rest)*);
    };

    // Parse offset datetime `key = 1979-05-27T00:32:00-07:00`.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt - $tzh:tt : $tzm:tt $($rest:tt)*) => {
        sane_internal!(@topleveldatetime $root [$($path)*] $($($k)-+).+ = ($yr - $mo - $dhr : $min : $sec - $tzh : $tzm) $($rest)*);
    };
    // Space instead of T.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt - $tzh:tt : $tzm:tt $($rest:tt)*) => {
        sane_internal!(@topleveldatetime $root [$($path)*] $($($k)-+).+ = ($yr - $mo - $day T $hr : $min : $sec - $tzh : $tzm) $($rest)*);
    };

    // Parse local datetime `key = 1979-05-27T00:32:00.999999`.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt . $frac:tt $($rest:tt)*) => {
        sane_internal!(@topleveldatetime $root [$($path)*] $($($k)-+).+ = ($yr - $mo - $dhr : $min : $sec . $frac) $($rest)*);
    };
    // Space instead of T.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt . $frac:tt $($rest:tt)*) => {
        sane_internal!(@topleveldatetime $root [$($path)*] $($($k)-+).+ = ($yr - $mo - $day T $hr : $min : $sec . $frac) $($rest)*);
    };

    // Parse offset datetime `key = 1979-05-27T07:32:00Z` and local datetime `key = 1979-05-27T07:32:00`.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt $($rest:tt)*) => {
        sane_internal!(@topleveldatetime $root [$($path)*] $($($k)-+).+ = ($yr - $mo - $dhr : $min : $sec) $($rest)*);
    };
    // Space instead of T.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt $($rest:tt)*) => {
        sane_internal!(@topleveldatetime $root [$($path)*] $($($k)-+).+ = ($yr - $mo - $day T $hr : $min : $sec) $($rest)*);
    };

    // Parse local date `key = 1979-05-27`.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $yr:tt - $mo:tt - $day:tt $($rest:tt)*) => {
        sane_internal!(@topleveldatetime $root [$($path)*] $($($k)-+).+ = ($yr - $mo - $day) $($rest)*);
    };

    // Parse local time `key = 00:32:00.999999`.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $hr:tt : $min:tt : $sec:tt . $frac:tt $($rest:tt)*) => {
        sane_internal!(@topleveldatetime $root [$($path)*] $($($k)-+).+ = ($hr : $min : $sec . $frac) $($rest)*);
    };

    // Parse local time `key = 07:32:00`.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $hr:tt : $min:tt : $sec:tt $($rest:tt)*) => {
        sane_internal!(@topleveldatetime $root [$($path)*] $($($k)-+).+ = ($hr : $min : $sec) $($rest)*);
    };

    // Parse any other `key = value` including string, inline list, inline
    // map, number, and boolean.
    (@toplevel $root:ident [$($path:tt)*] $($($k:tt)-+).+ = $v:tt $($rest:tt)*) => {{
        $crate::macros::insert_sane(
            &mut $root,
            &[$($path)* $(&concat!($("-", sane_internal!(@path $k),)+)[1..], )+],
            sane_internal!(@value $v));
        sane_internal!(@toplevel $root [$($path)*] $($rest)*);
    }};

    // Parse list header `[[bin]]`.
    (@toplevel $root:ident $oldpath:tt [[$($($path:tt)-+).+]] $($rest:tt)*) => {
        $crate::macros::push_sane(
            &mut $root,
            &[$(&concat!($("-", sane_internal!(@path $path),)+)[1..],)+]);
        sane_internal!(@toplevel $root [$(&concat!($("-", sane_internal!(@path $path),)+)[1..],)+] $($rest)*);
    };

    // Parse map header `[patch.crates-io]`.
    (@toplevel $root:ident $oldpath:tt [$($($path:tt)-+).+] $($rest:tt)*) => {
        $crate::macros::insert_sane(
            &mut $root,
            &[$(&concat!($("-", sane_internal!(@path $path),)+)[1..],)+],
            $crate::Value::Map($crate::value::Map::new()));
        sane_internal!(@toplevel $root [$(&concat!($("-", sane_internal!(@path $path),)+)[1..],)+] $($rest)*);
    };

    // Parse datetime from string and insert into map.
    (@topleveldatetime $root:ident [$($path:tt)*] $($($k:tt)-+).+ = ($($datetime:tt)+) $($rest:tt)*) => {
        $crate::macros::insert_sane(
            &mut $root,
            &[$($path)* $(&concat!($("-", sane_internal!(@path $k),)+)[1..], )+],
            $crate::Value::Datetime(concat!($(stringify!($datetime)),+).parse().unwrap()));
        sane_internal!(@toplevel $root [$($path)*] $($rest)*);
    };

    // Turn a path segment into a string.
    (@path $ident:ident) => {
        stringify!($ident)
    };

    // For a path segment that is not an ident, expect that it is already a
    // quoted string, like in `[target."cfg(windows)".dependencies]`.
    (@path $quoted:tt) => {
        $quoted
    };

    // Construct a Value from an inline map.
    (@value { $($inline:tt)* }) => {{
        let mut map = $crate::Value::Map($crate::value::Map::new());
        sane_internal!(@trailingcomma (@map map) $($inline)*);
        map
    }};

    // Construct a Value from an inline list.
    (@value [ $($inline:tt)* ]) => {{
        let mut list = $crate::value::List::new();
        sane_internal!(@trailingcomma (@list list) $($inline)*);
        $crate::Value::List(list)
    }};

    (@value (-nan)) => {
        $crate::Value::Float(-::std::f64::NAN)
    };

    (@value (nan)) => {
        $crate::Value::Float(::std::f64::NAN)
    };

    (@value nan) => {
        $crate::Value::Float(::std::f64::NAN)
    };

    (@value (-inf)) => {
        $crate::Value::Float(::std::f64::NEG_INFINITY)
    };

    (@value (inf)) => {
        $crate::Value::Float(::std::f64::INFINITY)
    };

    (@value inf) => {
        $crate::Value::Float(::std::f64::INFINITY)
    };

    // Construct a Value from any other type, probably string or boolean or number.
    (@value $v:tt) => {{
        // TODO: Implement this with something like serde_json::to_value instead.
        let de = $crate::macros::IntoDeserializer::<$crate::de::Error>::into_deserializer($v);
        <$crate::Value as $crate::macros::Deserialize>::deserialize(de).unwrap()
    }};

    // Base case of inline map.
    (@map $root:ident) => {};

    // Parse negative number `key = -value`.
    (@map $root:ident $($($k:tt)-+).+ = - $v:tt , $($rest:tt)*) => {
        sane_internal!(@map $root $($($k)-+).+ = (-$v) , $($rest)*);
    };

    // Parse positive number `key = +value`.
    (@map $root:ident $($($k:tt)-+).+ = + $v:tt , $($rest:tt)*) => {
        sane_internal!(@map $root $($($k)-+).+ = ($v) , $($rest)*);
    };

    // Parse offset datetime `key = 1979-05-27T00:32:00.999999-07:00`.
    (@map $root:ident $($($k:tt)-+).+ = $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt . $frac:tt - $tzh:tt : $tzm:tt , $($rest:tt)*) => {
        sane_internal!(@mapdatetime $root $($($k)-+).+ = ($yr - $mo - $dhr : $min : $sec . $frac - $tzh : $tzm) $($rest)*);
    };
    // Space instead of T.
    (@map $root:ident $($($k:tt)-+).+ = $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt . $frac:tt - $tzh:tt : $tzm:tt , $($rest:tt)*) => {
        sane_internal!(@mapdatetime $root $($($k)-+).+ = ($yr - $mo - $day T $hr : $min : $sec . $frac - $tzh : $tzm) $($rest)*);
    };

    // Parse offset datetime `key = 1979-05-27T00:32:00-07:00`.
    (@map $root:ident $($($k:tt)-+).+ = $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt - $tzh:tt : $tzm:tt , $($rest:tt)*) => {
        sane_internal!(@mapdatetime $root $($($k)-+).+ = ($yr - $mo - $dhr : $min : $sec - $tzh : $tzm) $($rest)*);
    };
    // Space instead of T.
    (@map $root:ident $($($k:tt)-+).+ = $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt - $tzh:tt : $tzm:tt , $($rest:tt)*) => {
        sane_internal!(@mapdatetime $root $($($k)-+).+ = ($yr - $mo - $day T $hr : $min : $sec - $tzh : $tzm) $($rest)*);
    };

    // Parse local datetime `key = 1979-05-27T00:32:00.999999`.
    (@map $root:ident $($($k:tt)-+).+ = $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt . $frac:tt , $($rest:tt)*) => {
        sane_internal!(@mapdatetime $root $($($k)-+).+ = ($yr - $mo - $dhr : $min : $sec . $frac) $($rest)*);
    };
    // Space instead of T.
    (@map $root:ident $($($k:tt)-+).+ = $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt . $frac:tt , $($rest:tt)*) => {
        sane_internal!(@mapdatetime $root $($($k)-+).+ = ($yr - $mo - $day T $hr : $min : $sec . $frac) $($rest)*);
    };

    // Parse offset datetime `key = 1979-05-27T07:32:00Z` and local datetime `key = 1979-05-27T07:32:00`.
    (@map $root:ident $($($k:tt)-+).+ = $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt , $($rest:tt)*) => {
        sane_internal!(@mapdatetime $root $($($k)-+).+ = ($yr - $mo - $dhr : $min : $sec) $($rest)*);
    };
    // Space instead of T.
    (@map $root:ident $($($k:tt)-+).+ = $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt , $($rest:tt)*) => {
        sane_internal!(@mapdatetime $root $($($k)-+).+ = ($yr - $mo - $day T $hr : $min : $sec) $($rest)*);
    };

    // Parse local date `key = 1979-05-27`.
    (@map $root:ident $($($k:tt)-+).+ = $yr:tt - $mo:tt - $day:tt , $($rest:tt)*) => {
        sane_internal!(@mapdatetime $root $($($k)-+).+ = ($yr - $mo - $day) $($rest)*);
    };

    // Parse local time `key = 00:32:00.999999`.
    (@map $root:ident $($($k:tt)-+).+ = $hr:tt : $min:tt : $sec:tt . $frac:tt , $($rest:tt)*) => {
        sane_internal!(@mapdatetime $root $($($k)-+).+ = ($hr : $min : $sec . $frac) $($rest)*);
    };

    // Parse local time `key = 07:32:00`.
    (@map $root:ident $($($k:tt)-+).+ = $hr:tt : $min:tt : $sec:tt , $($rest:tt)*) => {
        sane_internal!(@mapdatetime $root $($($k)-+).+ = ($hr : $min : $sec) $($rest)*);
    };

    // Parse any other type, probably string or boolean or number.
    (@map $root:ident $($($k:tt)-+).+ = $v:tt , $($rest:tt)*) => {
        $crate::macros::insert_sane(
            &mut $root,
            &[$(&concat!($("-", sane_internal!(@path $k),)+)[1..], )+],
            sane_internal!(@value $v));
        sane_internal!(@map $root $($rest)*);
    };

    // Parse a Datetime from string and continue in @map state.
    (@mapdatetime $root:ident $($($k:tt)-+).+ = ($($datetime:tt)*) $($rest:tt)*) => {
        $crate::macros::insert_sane(
            &mut $root,
            &[$(&concat!($("-", sane_internal!(@path $k),)+)[1..], )+],
            $crate::Value::Datetime(concat!($(stringify!($datetime)),+).parse().unwrap()));
        sane_internal!(@map $root $($rest)*);
    };

    // Base case of inline list.
    (@list $root:ident) => {};

    // Parse negative number `-value`.
    (@list $root:ident - $v:tt , $($rest:tt)*) => {
        sane_internal!(@list $root (-$v) , $($rest)*);
    };

    // Parse positive number `+value`.
    (@list $root:ident + $v:tt , $($rest:tt)*) => {
        sane_internal!(@list $root ($v) , $($rest)*);
    };

    // Parse offset datetime `1979-05-27T00:32:00.999999-07:00`.
    (@list $root:ident $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt . $frac:tt - $tzh:tt : $tzm:tt , $($rest:tt)*) => {
        sane_internal!(@listdatetime $root ($yr - $mo - $dhr : $min : $sec . $frac - $tzh : $tzm) $($rest)*);
    };
    // Space instead of T.
    (@list $root:ident $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt . $frac:tt - $tzh:tt : $tzm:tt , $($rest:tt)*) => {
        sane_internal!(@listdatetime $root ($yr - $mo - $day T $hr : $min : $sec . $frac - $tzh : $tzm) $($rest)*);
    };

    // Parse offset datetime `1979-05-27T00:32:00-07:00`.
    (@list $root:ident $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt - $tzh:tt : $tzm:tt , $($rest:tt)*) => {
        sane_internal!(@listdatetime $root ($yr - $mo - $dhr : $min : $sec - $tzh : $tzm) $($rest)*);
    };
    // Space instead of T.
    (@list $root:ident $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt - $tzh:tt : $tzm:tt , $($rest:tt)*) => {
        sane_internal!(@listdatetime $root ($yr - $mo - $day T $hr : $min : $sec - $tzh : $tzm) $($rest)*);
    };

    // Parse local datetime `1979-05-27T00:32:00.999999`.
    (@list $root:ident $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt . $frac:tt , $($rest:tt)*) => {
        sane_internal!(@listdatetime $root ($yr - $mo - $dhr : $min : $sec . $frac) $($rest)*);
    };
    // Space instead of T.
    (@list $root:ident $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt . $frac:tt , $($rest:tt)*) => {
        sane_internal!(@listdatetime $root ($yr - $mo - $day T $hr : $min : $sec . $frac) $($rest)*);
    };

    // Parse offset datetime `1979-05-27T07:32:00Z` and local datetime `1979-05-27T07:32:00`.
    (@list $root:ident $yr:tt - $mo:tt - $dhr:tt : $min:tt : $sec:tt , $($rest:tt)*) => {
        sane_internal!(@listdatetime $root ($yr - $mo - $dhr : $min : $sec) $($rest)*);
    };
    // Space instead of T.
    (@list $root:ident $yr:tt - $mo:tt - $day:tt $hr:tt : $min:tt : $sec:tt , $($rest:tt)*) => {
        sane_internal!(@listdatetime $root ($yr - $mo - $day T $hr : $min : $sec) $($rest)*);
    };

    // Parse local date `1979-05-27`.
    (@list $root:ident $yr:tt - $mo:tt - $day:tt , $($rest:tt)*) => {
        sane_internal!(@listdatetime $root ($yr - $mo - $day) $($rest)*);
    };

    // Parse local time `00:32:00.999999`.
    (@list $root:ident $hr:tt : $min:tt : $sec:tt . $frac:tt , $($rest:tt)*) => {
        sane_internal!(@listdatetime $root ($hr : $min : $sec . $frac) $($rest)*);
    };

    // Parse local time `07:32:00`.
    (@list $root:ident $hr:tt : $min:tt : $sec:tt , $($rest:tt)*) => {
        sane_internal!(@listdatetime $root ($hr : $min : $sec) $($rest)*);
    };

    // Parse any other type, probably string or boolean or number.
    (@list $root:ident $v:tt , $($rest:tt)*) => {
        $root.push(sane_internal!(@value $v));
        sane_internal!(@list $root $($rest)*);
    };

    // Parse a Datetime from string and continue in @list state.
    (@listdatetime $root:ident ($($datetime:tt)*) $($rest:tt)*) => {
        $root.push($crate::Value::Datetime(concat!($(stringify!($datetime)),+).parse().unwrap()));
        sane_internal!(@list $root $($rest)*);
    };

    // No trailing comma required if the tokens are empty.
    (@trailingcomma ($($args:tt)*)) => {
        sane_internal!($($args)*);
    };

    // Tokens end with a trailing comma, do not append another one.
    (@trailingcomma ($($args:tt)*) ,) => {
        sane_internal!($($args)* ,);
    };

    // Tokens end with something other than comma, append a trailing comma.
    (@trailingcomma ($($args:tt)*) $last:tt) => {
        sane_internal!($($args)* $last ,);
    };

    // Not yet at the last token.
    (@trailingcomma ($($args:tt)*) $first:tt $($rest:tt)+) => {
        sane_internal!(@trailingcomma ($($args)* $first) $($rest)+);
    };
}

// // Called when parsing a `key = value` pair.
// // Inserts an entry into the map at the given path.
// pub fn insert_sane(root: &mut Value, path: &[&str], value: Value) {
//     *traverse(root, path) = value;
// }
//
// // Called when parsing an `[[list header]]`.
// // Pushes an empty map onto the list at the given path.
// pub fn push_sane(root: &mut Value, path: &[&str]) {
//     let target = traverse(root, path);
//     if !target.is_list() {
//         *target = Value::List(List::new());
//     }
//     target
//         .as_list_mut()
//         .unwrap()
//         .push(Value::Map(Map::new()));
// }

// fn traverse<'a>(root: &'a mut Value, path: &[&str]) -> &'a mut Value {
//     let mut cur = root;
//     for &key in path {
//         // Lexical lifetimes :D
//         let cur1 = cur;
//         let cur2;

//         // From the SANE spec:
//         //
//         // > Each double-bracketed sub-map will belong to the most recently
//         // > defined map element above it.
//         if cur1.is_list() {
//             cur2 = cur1.as_list_mut().unwrap().last_mut().unwrap();
//         } else {
//             cur2 = cur1;
//         };

//         // We are about to index into this value, so it better be a map.
//         if !cur2.is_map() {
//             *cur2 = Value::Map(Map::new());
//         }

//         if !cur2.as_map().unwrap().contains_key(key) {
//             // Insert an empty map for the next loop iteration to point to.
//             let empty = Value::Map(Map::new());
//             cur2.as_map_mut().unwrap().insert(key.to_owned(), empty);
//         }

//         // Step into the current map.
//         cur = cur2.as_map_mut().unwrap().get_mut(key).unwrap();
//     }
//     cur
// }
