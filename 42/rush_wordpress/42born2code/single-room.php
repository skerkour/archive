<?php get_header() ?>
<div id="contenti">
		<div class="ftroom_topimg" style="background: url('<?php
			$thumb_id = get_post_thumbnail_id();
			$thumb_url = wp_get_attachment_image_src($thumb_id,'thumbnail-size', true);
			echo $thumb_url[0];
			?>') no-repeat center;-webkit-background-size: cover;background-size: cover;">
		</div>
		<div style="margin-top: -66.5px; background: none repeat scroll 0% 0% rgba(0, 0, 0, 0.7); margin-bottom: 69px; border-top-left-radius:3px;border-top-right-radius:3px;"><h3 style="float: right; color: rgb(232, 231, 227); padding: 10px; background: none repeat scroll 0% 0% rgba(60, 63, 64, 0.8);">
			<?php $ppn = get_post_meta($post->ID, 'ftmetain_ppn'); echo $ppn[0]; ?> € par nuit</h3>
		</div>
	<?php the_post() ?>
	<div class="entry-single">
		<div class="row">
			<div class="col-md-4" id=ft_room_usercol>
			<?php
				function get_avatar_url($get_avatar) {
					preg_match("/src='(.*?)'/i", $get_avatar, $matches);
					return $matches[1];
				}
				$uname = get_the_author();
				$user = get_user_by('slug', $uname);
				?>
				<div>
					<div class="circular" style="background: url('<?php echo get_avatar_url(get_avatar($user->id, 160)); ?>') no-repeat;" ></div>
			<?php $udata = get_userdata($user->id); ?>
				<a href="<?php echo bloginfo('url'); ?>/?page_id=39&uid=<?php echo $user->id; ?>" ><?php echo $uname; ?></a> (registered since <?php echo $udata->user_registered; ?>)
				</div>
				<div class="entry-meta-top">
					<!-- <span class="entry-meta-sep">|</span>
					<span class="entry-comm">Publié dans <?php /* the_category(', ');*/ ?></span>-->
				</div>
			</div>
			<div class="col-md-4">
				<h3 class="entry-title"><?php the_title(); ?></h3>
				<span class="entry-date"><?php unset($previousday); printf( __( '%1$s', 'wpbx' ), the_date( 'D, j M Y', '', '', false ) ) ?></span>
				<br /><br /><h4>Type de logement :</h4>
					<?php
						$type_loge = get_post_meta($post->ID, 'type_loge');
						if ($type_loge[0] == 'appartement') { ?>
							<img src="<?php bloginfo('template_directory'); ?>/images/apartment.png" alt="APPARTEMENT" width="42" heigth="42">
						<?php } else { ?>
							<img src="<?php bloginfo('template_directory'); ?>/images/house.png" alt="MAISON" width="42" heigth="42"> 
						<?php } echo($type_loge[0]); ?><br />
				<h4>Equipement :</h4>
				<?php
					$check_cuisine = get_post_meta($post->ID, 'cuisine');
					$check_chauffage = get_post_meta($post->ID, 'chauffage');
					$check_internet = get_post_meta($post->ID, 'internet');
					if ($check_cuisine[0] == 'yes') { ?>
					<img src="<?php bloginfo('template_directory'); ?>/images/kitchen.png" alt="KITCHEN" width="42" heigth="42"> Cuisine <br />
					<?php }
					if ($check_chauffage[0] == 'yes') { ?>
						<img src="<?php bloginfo('template_directory'); ?>/images/heat.png" alt="HEAT" width="42" heigth="42"> Chauffage <br />
					<?php }
					if ($check_internet[0] == 'yes') { ?>
						<img src="<?php bloginfo('template_directory'); ?>/images/internet.png" alt="INTERNET" width="42" heigth="42"> Internet <br />
					<?php } ?>
				<br /><h4>Description :</h4>
				<?php the_content() ?>
			</div>
			<div class="col-md-4">
				<?php the_tags( __( '<span class="tag-links">Tags: ', 'wpbx' ), ", ", "</span>\n" ) ?>
			</div>
		</div>
	</div><!-- .post -->
	<?php comments_template(); ?>
</div><!-- #content -->
<?php get_footer() ?>
