<?php /*
* Template Name: city page
*/

get_header();
?>
<div class="row ftrowcenter" >
<?php
	if (isset($_GET['city'])) {
		$the_query = new WP_Query(array('location' => $_GET['city']));
		if ($the_query->have_posts()) {
			while ($the_query->have_posts()) {
				$the_query->the_post();
				$title = get_the_title();
				$uname = get_the_author();
				$user = get_user_by('slug', $uname);
				$thumb_id = get_post_thumbnail_id();
				$permalink = get_permalink($post->ID);
				$ppn = get_post_meta($post->ID, 'ftmetain_ppn');
				$thumb_url = wp_get_attachment_image_src($thumb_id, 'thumbnail-size', true); ?>
				<div class="col-md-4" >
					<div style="height:333px;width:333px; background: url('<?php echo $thumb_url[0]; ?>') no-repeat center;-webkit-background-size: cover;background-size: cover; cursor: pointer;" onclick="window.location='<?php echo $permalink; ?>'" >
					<h4 style="float: right; color: rgb(232, 231, 227); padding: 10px; background: none repeat scroll 0% 0% rgba(60, 63, 64, 0.8); margin-top:0px;" >
						<?php echo $ppn[0]; ?> € par nuit</h4>
					</div>
					<a href="<?php echo $permalink; ?>"><?php echo $title; ?></a>
				</div>
			<?php }
		}
		else
			echo '<div style="text-align:center;"><h2>no result found :/ </h2></div>';
	}
	else
		echo '<div style="text-align:center;"><h2>no result found :/ </h2></div>';
?>
</div>
<?php get_footer() ?>
