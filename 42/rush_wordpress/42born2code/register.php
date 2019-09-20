<?php
if (!empty($_POST['password']) && !empty($_POST['login']) && !empty($_POST['email'])) {
	$username = $_POST['login'];
	$password = $_POST['password'];
	$email = $_POST['email'];
	define('WP_USE_THEMES', false);
	require_once (dirname (dirname (__FILE__)) . '/../../wp-blog-header.php');
	require_once (dirname (dirname (__FILE__)) . '/../../wp-includes/registration.php');
	$status = wp_create_user($username, $password, $email);
	if (is_wp_error($status)) { ?>
		<script>alert('error during registration');</script>
		<script>document.location="<?php bloginfo('url'); ?>";</script>
<?php	}
	else { ?>
		<script>alert('registration done');</script>
		<script>document.location="<?php bloginfo('url'); ?>";</script>
<?php	}
}
else {
?>
	<div id="lightb_register" class="white_content">
		<form class="form-horizontal" role="form" action="<?php bloginfo('template_directory');?>/register.php" method="post">
			<div class="form-group">
				<label class="control-label col-sm-2" for="email">Email:</label>
				<div class="col-sm-10">
					<input type="email" class="form-control" id="email" placeholder="Enter email" name="email">
				</div>
			</div>
			<div class="form-group">
				<label class="control-label col-sm-2" for="login">Login:</label>
				<div class="col-sm-10">
					<input type="text" class="form-control" id="login" placeholder="Enter Login" name="login">
				</div>
			</div>
			<div class="form-group">
				<label class="control-label col-sm-2" for="pwd">Password:</label>
				<div class="col-sm-10">
					<input type="password" class="form-control" id="pwd" placeholder="Enter password" name="password">
				</div>
			</div>
			<div class="form-group">
				<div class="col-sm-offset-2 col-sm-10"></div>
			</div>
			<div class="form-group">
				<div class="col-sm-offset-2 col-sm-10">
					<button type="submit" class="btn btn-default" id="submit_register">Submit</button>
				</div>
			</div>
		</form>
	</div>
<?php
}
?>
