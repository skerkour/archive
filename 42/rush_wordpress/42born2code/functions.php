<?php

add_action( 'init', 'register_my_menus' );
function register_my_menus() {
	register_nav_menus(
		array(
			'primary-menu' => __( 'Main Menu' ),
		));
}

add_theme_support( 'post-thumbnails' );
set_post_thumbnail_size( 200, 150, true ); // Normal post thumbnails

add_custom_background();

// Custom comment listing
function wpbx_comment($comment, $args, $depth) {
	$GLOBALS['comment'] = $comment;
	$commenter = get_comment_author_link();
	if ( ereg( '<a[^>]* class=[^>]+>', $commenter ) ) {
		$commenter = ereg_replace( '(<a[^>]* class=[\'"]?)', '\\1url ' , $commenter );
	} else {
		$commenter = ereg_replace( '(<a )/', '\\1class="url "' , $commenter );
	}
	$avatar_email = get_comment_author_email();
    $avatarURL = get_bloginfo('template_directory');
	$avatar = str_replace( "class='avatar", "class='avatar", get_avatar( $avatar_email, 40, $default = $avatarURL . '/images/gravatar-blank.jpg' ) );
?>
	<li <?php comment_class(); ?> id="comment-<?php comment_ID() ?>">
		<div id="div-comment-<?php comment_ID(); ?>">
			<div class="comment-author vcard">
				<?php echo $avatar . ' <span class="fn n">' . $commenter . '</span>'; ?>
			</div>
			<div class="comment-meta">
				<?php printf(__('%1$s <span class="meta-sep">|</span> <a href="%3$s" title="Permalink to this comment">Permalink</a>', 'wpbx'),
					get_comment_date('j M Y', '', '', false),
					get_comment_time(),
					'#comment-' . get_comment_ID() );
					edit_comment_link(__('Edit', 'wpbx'), ' <span class="meta-sep">|</span> <span class="edit-link">', '</span>');
				?>
				<span class="reply-link">
					<span class="meta-sep">|</span> <?php comment_reply_link(array_merge( $args, array('add_below' => 'div-comment', 'depth' => $depth, 'max_depth' => $args['max_depth']))) ?>
				</span>
			</div>

			<?php if ($comment->comment_approved == '0') _e("\t\t\t\t\t<span class='unapproved'>Your comment is awaiting moderation.</span>\n", 'wpbx') ?>

			<div class="comment-content"><?php comment_text() ?></div>
		</div>
<?php
}
// wpbx_comment()

// For category lists on category archives: Returns other categories except the current one (redundant)
function wpbx_cat_also_in($glue) {
	$current_cat = single_cat_title( '', false );
	$separator = "\n";
	$cats = explode( $separator, get_the_category_list($separator) );
	foreach ( $cats as $i => $str ) {
		if ( strstr( $str, ">$current_cat<" ) ) {
			unset($cats[$i]);
			break;
		}
	}
	if ( empty($cats) )
		return false;

	return trim(join( $glue, $cats ));
}

// For tag lists on tag archives: Returns other tags except the current one (redundant)
function wpbx_tag_also_in($glue) {
	$current_tag = single_tag_title( '', '',  false );
	$separator = "\n";
	$tags = explode( $separator, get_the_tag_list( "", "$separator", "" ) );
	foreach ( $tags as $i => $str ) {
		if ( strstr( $str, ">$current_tag<" ) ) {
			unset($tags[$i]);
			break;
		}
	}
	if ( empty($tags) )
		return false;

	return trim(join( $glue, $tags ));
}

// Generate custom excerpt length
function wpbx_excerpt_length($length) {
	return 75;
}
add_filter('excerpt_length', 'wpbx_excerpt_length');

/*
// Widgets plugin: intializes the plugin after the widgets above have passed snuff
function wpbx_widgets_init() {
	if ( !function_exists('register_sidebars') ) {
		return;
	}
	// Formats the theme widgets, adding readability-improving whitespace
	$p = array(
		'before_widget'  =>   '<li id="%1$s" class="widget %2$s">',
		'after_widget'   =>   "</li>\n",
		'before_title'   =>   '<h3 class="widget-title">',
		'after_title'    =>   "</h3>\n"
	);
	register_sidebars( 1, $p );
} // ici on ferme la fonction function wpbx_widgets_init()
*/

// Runs our code at the end to check that everything needed has loaded
add_action( 'init', 'wpbx_widgets_init' );

// Adds filters for the description/meta content
add_filter( 'archive_meta', 'wptexturize' );
add_filter( 'archive_meta', 'convert_smilies' );
add_filter( 'archive_meta', 'convert_chars' );
add_filter( 'archive_meta', 'wpautop' );

// Translate, if applicable
load_theme_textdomain('wpbx');


// Construct the WordPress header
remove_action('wp_head', 'start_post_rel_link');
remove_action('wp_head', 'index_rel_link');
remove_action('wp_head', 'adjacent_posts_rel_link');
remove_action('wp_head', 'next_post_rel_link');
remove_action('wp_head', 'previous_post_rel_link');

if (function_exists('register_sidebar')) {
	register_sidebar(array( 'name' => 'Footer',
		'before_widget' => '<div class="ftsidebar_footer">',
		'after_widget' => '</div>',
		'before_title' => '<h2 class="ftsidebar_footer_tittle">',
		'after_title' => '</h2>',
	));
}

register_post_type('room',
	array(
		'label' => __('room'),
		'singular_label' => __('room'),
		'public' => true,
		'show_ui' => true,
		'capability_type' => 'post',
		'hierarchical' => false,
		'supports' => array('title', 'excerpt', 'thumbnail', 'comments', 'editor', 'page-attributes' )
	)
);
register_taxonomy('location', 'room', array( 'hierarchical' => true, 'label' => 'Location', 'query_var' => true, 'rewrite' => true));

add_action('add_meta_boxes','ftmeta_ppn_init');
function ftmetaf_ppn($post) {
	$ppn = get_post_meta($post->ID, 'ftmetain_ppn', false);
	echo '<input type="number" name="ftmetain_ppn" value="'.$ppn[0].'" />';
}
function ftmeta_ppn_init() {
	add_meta_box('ft_meta_ppn', 'Prix par nuit', 'ftmetaf_ppn', 'room');
}

add_action('add_meta_boxes','ftmeta_prop_type_init');
function ftmetaf_prop_type($post) {
	$type_loge = get_post_meta($post->ID, 'type_loge', false);
	if ($type_loge[0] == "maison") {
		echo '<select name="type_loge">';
		echo '<option value="maison" selected="selected" >Maison</option>';
		echo '<option value="appartement">Appartement</option>';
		echo '</select>';
	}
	else {
		echo '<select name="type_loge">';
		echo '<option value="maison">Maison</option>';
		echo '<option value="appartement" selected="selected">Appartement</option>';
		echo '</select>';
	}
}
function ftmeta_prop_type_init() {
	add_meta_box('ft_meta_prop_type', 'Type de propriete', 'ftmetaf_prop_type', 'room');
}

add_action('add_meta_boxes','ftmeta_equip_init');
function ftmetaf_eauip($post) {
	$check_cuisine = get_post_meta($post->ID, 'cuisine', false);
	if ($check_cuisine[0] == 'yes') 
		$state_cuisine = 'checked="checked"';
	else
		$state_cuisine = 'class="nonoob"';
	$check_chauffage = get_post_meta($post->ID, 'chauffage', false);
	if ($check_chauffage[0] == 'yes')
		$state_chauffage = 'checked="checked"';
	else
		$state_chauffage = 'class="nonoob"';
	$check_internet = get_post_meta($post->ID, 'internet', false);
	if ($check_internet[0] == 'yes')
		$state_internet = 'checked="checked"';
	else
		$state_internet = 'class="nonoob"';

	echo '<label for="stuff">Equipement : </label><br />';
	echo '<input type="checkbox" name="cuisine" '.$state_cuisine.' value="Cuisine" />Cuisine<br />';
	echo '<input type="checkbox" name="chauffage" '.$state_chauffage.' value="Chauffage" />Chauffage<br />';
	echo '<input type="checkbox" name="internet" '.$state_internet.' value="Internet" />Internet<br />';
}
function ftmeta_equip_init() {
	add_meta_box('ft_meta_equip', 'Equipement', 'ftmetaf_eauip', 'room');
}

add_action('save_post','save_metaboxes');
function save_metaboxes($post_ID) {
	if (isset($_POST['ftmetain_ppn']))
		update_post_meta($post_ID, 'ftmetain_ppn', esc_html($_POST['ftmetain_ppn']));
	if (isset($_POST['type_loge']))
		update_post_meta($post_ID, 'type_loge', esc_html($_POST['type_loge']));
	
	if (isset($_POST['cuisine']))
		update_post_meta($post_ID, 'cuisine', 'yes');
	else
		update_post_meta($post_ID, 'cuisine', '');
	if (isset($_POST['chauffage']))
		update_post_meta($post_ID, 'chauffage', 'yes');
	else
		update_post_meta($post_ID, 'chauffage', '');
	if (isset($_POST['internet']))
		update_post_meta($post_ID, 'internet', 'yes');
	else
		update_post_meta($post_ID, 'internet', '');
}
