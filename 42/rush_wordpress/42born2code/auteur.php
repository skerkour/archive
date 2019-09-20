<?php
/*
* Template Name: author page
*/
function get_avatar_url($get_avatar) {
	preg_match("/src='(.*?)'/i", $get_avatar, $matches);
	return $matches[1];
}
get_header();

if (!isset($_GET['uid'])) {
	echo '<div style="text-align:center;"><h2>there is nothing to do here :/ </h2></div>';
}
else {
	$uid = $_GET['uid'];
	$user = get_user_by('id', $uid);
	$udata = get_userdata(uid);

?>
<div class="row ftrowcenter" >
	<div class="col-md-4" >
		<div style="background: url('<?php echo get_avatar_url(get_avatar($uid, 160)); ?>') no-repeat;height:160px;width:160px;" ></div>
		<div class="user-infosbox">
			<h4><?php echo $user->nickname; ?></h4>
			<span>Facebook&nbsp;: <?php echo $user->ft_facebook; ?></span><br />
			<span>Tel&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: <?php echo $user->ft_tel; ?></span><br />
			<span>Since&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: <?php echo $user->user_registered; ?></span><br />
		</div>	
	</div>
	<h4>Chambres que je loue</h4>
<?php
	/*$the_query = new WP_Query(array('author' => $user->nickname));*/
$args = array(
		  'post_type' => 'room',
		  'author' => $uid
		  );

	$the_query = null;
	$the_query = new WP_Query($args);
	if ($the_query->have_posts()) {
		while ($the_query->have_posts()) {
			$the_query->the_post();
			$title = get_the_title();
			$uname = get_the_author();
			$userr = get_user_by('slug', $uname);
			$thumb_id = get_post_thumbnail_id();
			$permalink = get_permalink($post->ID);
			$thumb_url = wp_get_attachment_image_src($thumb_id, 'thumbnail-size', true); ?>
			<div class="col-md-4" >
				<div style="height:333px;width:100%; background: url('<?php echo $thumb_url[0]; ?>') no-repeat center;-webkit-background-size: cover;background-size: cover; cursor:pointer;" onclick="window.location='<?php echo $permalink; ?>'" ></div>
				<a href="<?php echo $permalink; ?>"><?php echo $title; ?></a>
			</div>
<?php	}
	} ?>
</div>
<?php
}
get_footer(); ?>
