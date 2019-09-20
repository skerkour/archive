<?php
/**
* Plugin Name: ft social plugin
* Plugin URI: https://github.com/z0mboy/
* Description: A little plugin for eductionnal purpose
* Version: 1.0
* Author: z0mbie
* Author URI: https://github.com/z0mboy/
**/

add_action('personal_options','ft_plugin_add_options');
add_action('personal_options_update','ft_plugin_update');

function ft_plugin_add_options() {
	$user_id = get_current_user_id();
	$ft_facebook = get_user_meta($user_id,'ft_facebook',true);
	if(!$ft_facebook) {
		add_user_meta($user_id, 'ft_facebook', '');
		$ft_facebook = '';
	}
	$ft_tel = get_user_meta($user_id,'ft_tel',true);
	if(!$ft_facebook) {
		add_user_meta($user_id, 'ft_tel', '');
		$ft_tel = '';
	}
  ?>
	<tr>
		<th scope="row"><label for="ft_facebook">Facebook</label></th>
		<td>
		<input name="ft_facebook" id="ft_facebook" value="<?php echo $ft_facebook; ?>" class="regular-text" type="text">
		</td>
	</tr>
	<tr>
		<th scope="row"><label for="ft_tel">Tel</label></th>
		<td>
		<input name="ft_tel" id="ft_tel" value="<?php echo $ft_tel; ?>" type="tel">
		</td>
	</tr>
<?php
}

function ft_plugin_update() {
	$user_id = get_current_user_id();
	if(isset($_POST['ft_tel'])) {
		$ft_tel = $_POST['ft_tel'];
		update_user_meta($user_id, 'ft_tel', $ft_tel);
	}
	if(isset($_POST['ft_facebook'])) {
		$ft_facebook = $_POST['ft_facebook'];
		update_user_meta($user_id, 'ft_facebook', $ft_facebook);
	}
}



add_action('admin_menu', 'ftsocial_plugin_settings');
function ftsocial_plugin_settings() {
	add_menu_page('Ft Social Settings', 'Ft Social Settings', 'publish_posts', 'ftsocial_settings', 'ftsocial_display_settings');
}

function ftsocial_display_settings() {
	$user_id = get_current_user_id();

	if (current_user_can('edit_user',$user_id)) {
		if (isset($_GET['ftsocial_tel']))
			update_user_meta($user_id, 'ft_tel', $_GET['ftsocial_tel']);
		if (isset($_GET['ftsocial_facebook']))
			update_user_meta($user_id, 'ft_facebook', $_GET['ftsocial_facebook']);
	}

	$ft_facebook = get_user_meta($user_id,'ft_facebook',true);
	if(!$ft_facebook) {
		add_user_meta($user_id, 'ft_facebook', '');
		$ft_facebook = '';
	}
	$ft_tel = get_user_meta($user_id,'ft_tel',true);
	if(!$ft_facebook) {
		add_user_meta($user_id, 'ft_tel', '');
		$ft_tel = '';
	}

	$html = '
	<div class="wrap">
			<form action="">
				Phone number :<br>
				<input type="tel" name="ftsocial_tel" value="'.$ft_tel.'" ><br>
				Facebook :<br>
				<input type="text" name="ftsocial_facebook" value="'.$ft_facebook.'" ><br>
				<input type="submit" value="Save">
				<input type="hidden" name="page" value="ftsocial_settings" />
			</form>
	</div>
';
    echo $html;
}
