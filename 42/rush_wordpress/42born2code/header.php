<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" <?php language_attributes() ?>>
<head profile="http://gmpg.org/xfn/11">

<meta http-equiv="content-type" content="<?php bloginfo('html_type') ?>; charset=<?php bloginfo('charset') ?>" />
<meta name="description" content="" />
<meta name="keywords" content="" />
<title><?php wp_title( '-', true, 'right' ); echo wp_specialchars( get_bloginfo('name'), 1 ) ?></title>
<link rel="stylesheet" href="<?php bloginfo('stylesheet_directory'); ?>/style.css" type="text/css" media="screen" />

	<!--[if lte IE 6]><script type="text/javascript" src="<?php bloginfo('template_url'); ?>/js/supersleight-min.js"></script><![endif]-->
<?php wp_enqueue_script(get_bloginfo('template_directory').'/js/jquery.js'); ?>
<?php wp_enqueue_script('superfish', get_bloginfo('template_directory').'/js/superfish.js', array('jquery'), '1.7'); ?>
<?php wp_enqueue_script(get_bloginfo('template_directory').'/js/nav.js'); ?>
<?php if (trim(get_option('ft_header_code')) <> "") { echo stripslashes(get_option('ft_header_code')); } ?>
<?php if (is_singular()) wp_enqueue_script('comment-reply'); ?>
<?php wp_enqueue_script( 'bootstrapjs', get_template_directory_uri() . '/js/bootstrap.min.js', array('jquery'), '', true ); ?>
<?php wp_head(); ?> <!-- #NE PAS SUPPRIMER cf. codex wp_head() -->
</head>
<body <?php body_class() ?>>
<!-- <div id="top">
	<div class="pads clearfix"><?php /* wp_nav_menu( array( 'theme_location' => 'secondary-menu', 'sort_column' => 'menu_order', 'container_class' => 'nav' ) ); */ ?>
	</div>
</div>-->
<div id="header">
	<nav id="ft_navheader" class="navbar navbar-inverse">
		<div class="container-fluid" id="ft_navheader_container">
			<div class="navbar-header">
				<button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
				</button>
				<a href="<?php echo get_option('home'); ?>" id="ft_headerlogo" navbar-brand><img id="site-logo" src="<?php
					bloginfo('template_directory');
					if (!is_home())
						echo "/images/airbnb_black.png\""; 
					else
						echo "/images/airbnb.png\""; ?>
				alt="<?php bloginfo('name'); ?>" style="padding-top: 9px;padding-left:9px;"/></a>
			</div>
			<div class="collapse navbar-collapse" id="myNavbar">
				<ul class="nav navbar-nav" style="padding-left:15px;">
					<li>
						<button type="button" class="btn btn-default dropdown-toggle navbar-btn" data-toggle="dropdown" aria-expanded="false" style="opacity: 0.8;">Naviguer <span class="caret"></span></button>
						<ul class="dropdown-menu ftdropnav" role="menu" style="margin-top: -9px;border-top-left-radius: 0px;border-top-right-radius: 5px;border-bottom-right-radius: 5px;border-left-right-radius: 5px;">
							<li><a href="<?php bloginfo('url');?>/?page_id=35&city=bruxelles">Bruxelles</a></li>
							<li><a href="<?php bloginfo('url');?>/?page_id=35&city=londres">Londres</a></li>
							<li><a href="<?php bloginfo('url');?>/?page_id=35&city=strasbourg">Strasbourg</a></li>
							<li class="divider"></li>
							<li><a href="#">San Francisco</a></li>
							<li><a href="#">Istanbul</a></li>
							<li><a href="#">Saint Petersbourg</a></li>
						</ul>
					</li>
				</ul>
				<?php if (!is_home()) { ?>
				<form class="navbar-form navbar-left" role="search" action="<?php echo $_SERVER['PHP_SELF']; ?>">
						<div class="form-group">
							<input type="text" class="form-control" placeholder="Search" name="s">
						</div>
						<button type="submit" class="btn btn-default">Go!</button>
					</form>
				<?php } ?>
				<ul class="nav navbar-nav navbar-right">
					<?php
					if (!is_user_logged_in()) { ?>
						<li class="ft_btnheader" ><button class="btn btn-success navbar-btn" onclick="document.location='<?php bloginfo('url'); ?>/wp-login.php'">se connecter</button></li>
					<li class="ft_btnheader" ><button class="btn btn-warning navbar-btn" onclick = "document.getElementById('lightb_register').style.display='block';document.getElementById('fade').style.display='block'">s'enregistrer</button></li>
					<?php }
					else { ?>
					<li class="ft_btnheader" ><button class="btn btn-danger navbar-btn" onclick="window.location='<?php echo wp_logout_url(get_permalink()) ?>'">Deconnexion</a></button></li>
					<?php } ?>
					<li class="ft_btnheader"><button class="btn btn-info navbar-btn" onclick="<?php 
					if (is_user_logged_in()) { ?>
						window.location='<?php echo get_admin_url(); ?>/edit.php?post_type=room';"
					<?php }
					else { ?>
					document.getElementById('lightb_connect').style.display='block';document.getElementById('fade').style.display='block'"
					<?php }
					?> >publier votre annonce</button></li>
				</ul>
			</div>
		</div>
	</nav>
</div><!--  #header -->

<?php if (!is_home()) { ?>
<div id="container" style="padding-top:62px;">
	<div class="pads clearfix">
<?php } ?>
