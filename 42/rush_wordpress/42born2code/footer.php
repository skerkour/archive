<?php if (!is_home()) { ?>
				<div id="lightb_connect" class="white_content">
					<div style="text-align: right;"><a href = "javascript:void(0)" onclick = "document.getElementById('lightb_connect').style.display='none';document.getElementById('fade').style.display='none'">Close</a></div>
					<form id="login" method="post" action="<?php echo wp_login_url( get_permalink() ) ?>">
					<label>Login :</label>
					<input type="text" value="" name="log" />
					<label>Mot de passe : </label>
					<input type="password" value="" name="pwd"  />
					<input type="submit" value="Connexion" />
					 </form>
				</div><div id="fade" class="black_overlay" onclick = "document.getElementById('lightb_connect').style.display='none';document.getElementById('lightb_register').style.display='none';document.getElementById('fade').style.display='none'"></div>
<?php get_template_part( 'register' ); ?>
</div><!-- #container -->
<?php } ?>

<div id="footer">
<?php if (!function_exists('dynamic_sidebar') || !dynamic_sidebar('Footer')) ?>
</div><!-- #footer -->
<?php wp_footer() ?> <!-- #NE PAS SUPPRIMER cf. codex wp_footer() -->
</body>
</html>
