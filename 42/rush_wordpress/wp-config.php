<?php
/**
 * The base configurations of the WordPress.
 *
 * This file has the following configurations: MySQL settings, Table Prefix,
 * Secret Keys, WordPress Language, and ABSPATH. You can find more information
 * by visiting {@link http://codex.wordpress.org/Editing_wp-config.php Editing
 * wp-config.php} Codex page. You can get the MySQL settings from your web host.
 *
 * This file is used by the wp-config.php creation script during the
 * installation. You don't have to use the web site, you can just copy this file
 * to "wp-config.php" and fill in the values.
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('DB_NAME', 'db_database');

/** MySQL database username */
define('DB_USER', 'Admin');

/** MySQL database password */
define('DB_PASSWORD', '123456');

/** MySQL hostname */
define('DB_HOST', 'localhost');

/** Database Charset to use in creating database tables. */
define('DB_CHARSET', 'utf8');

/** The Database Collate type. Don't change this if in doubt. */
define('DB_COLLATE', '');

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'e~8y19w7^Xg$*I m_k/)P!Qdk|YN|p5Rm!K@ga|^]`%>M^VUJ:kS@(BSMmg&LvSL');
define('SECURE_AUTH_KEY',  'x,/R1 xnp99),+1X<~ LFlBa-+]>&rtq>Z1@BYNY`on45yuS@t<=-L 6B;Y|t-=+');
define('LOGGED_IN_KEY',    'FJQ|]Am*+@(p_)#m_=+%n8Zx4~QBG;/}50:P5b7+M~c)+q#KE?ppKJMo!mldil}0');
define('NONCE_KEY',        'K>Z/Lrb{?0}hk*>$q3`5l%@yZ~9quO$d!}5ofwhOPUPMAXXM:ip*6CWa/)56F^+=');
define('AUTH_SALT',        '6W `}Z<z@|zPa7^9^|&7~H-!ROMZrjzfJrLQv|s;O=G:[WP%+:db7{=+/zx!LZKI');
define('SECURE_AUTH_SALT', 'ap$VrlatQ+IG6t:viU@OAJo!x~=&AYyAg^gbxXH 8nXXX*6vefR3-t7+i~R.ne~y');
define('LOGGED_IN_SALT',   '2M>SDT:@7I7ET;WkZ!J=^%~@I4d/u1U|``K2|-n-E3/#*>p,G{3V..dCWg9R}Nv~');
define('NONCE_SALT',       'vRe{v-Xq_6,2K*&RumDX?pJq+qNQS0/|5|xJWZ4&Y]vGu1)G{uNq&N|-/O{Rbg|-');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each a unique
 * prefix. Only numbers, letters, and underscores please!
 */
$table_prefix  = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 */
define('WP_DEBUG', false);

/* That's all, stop editing! Happy blogging. */

/** Absolute path to the WordPress directory. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Sets up WordPress vars and included files. */
require_once(ABSPATH . 'wp-settings.php');
