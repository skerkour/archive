<?php get_header();
?>

<!-- foutre image ici ! -->
<div id="container">
	<div id="ft_index_cont">
		<div class="pads clearfix">
			<div id="content_index" style="background-color: rgba(0, 0, 0, 0.0);">
			</div>
		</div>
		<div style="position: absolute;color:white; text-align:center;width:100%;margin-top: 96px;">
			<h1 >BIENVENUE A LA MAISON</h1>
			<h4>Louez des logements uniques aupres d'hotes locaux dans 190+ pays.</h4>
		</div>
		<div style="text-align:center;">
			<button class="btn btn-success" id="ft_btn_mode_emp" style="margin-top: 262px; opacity:0.85;" onclick="window.location='<?php bloginfo('url') ?>/?page_id=6'" >mode d'emploi</button>
		</div>
		<div id="ft_index_top">
			<div id="blocsearch" style="text-align: center; padding-top:14px;"> <?php include('searchform.php'); ?></div>
		</div>
	</div>
	<div id="lightb_connect" class="white_content">
		<form class="form-horizontal" role="form" action="<?php echo wp_login_url( get_permalink() ) ?>" method="post" >
			<div class="form-group">
				<label class="control-label col-sm-2" for="login">Login:</label>
				<div class="col-sm-10">
					<input type="text" class="form-control" id="login" placeholder="Enter Login" name="log">
				</div>
			</div>
			<div class="form-group">
				<label class="control-label col-sm-2" for="pwd">Password:</label>
				<div class="col-sm-10">
					<input type="password" class="form-control" id="pwd" placeholder="Enter password" name="pwd">
				</div>
			</div>
			<div class="form-group">
				<div class="col-sm-offset-2 col-sm-10"></div>
			</div>
			<div class="form-group">
				<div class="col-sm-offset-2 col-sm-10">
					<button type="submit" class="btn btn-success" >Log In !</button>
				</div>
			</div>
		</form>
	</div>
	<div id="fade" class="black_overlay" onclick = "document.getElementById('lightb_connect').style.display='none';document.getElementById('lightb_register').style.display='none';document.getElementById('fade').style.display='none'"></div>
	<?php get_template_part('register'); ?>
</div>

<div class="container">
	<div id="title_ftindex">
	<h1 style="color:#323538;">Juste pour le week end</h1>
	<h4 style="color:#323538;">Decouvrez de mouveaux lieux inspirants pres de chez vous.</h4>
	</div>
	<div class="row">
		<div class="col-md-4 ftindex_gridelem" ><div class="ftindex_imgs" style='background: url("<?php bloginfo('template_directory');?>/images/SF_ftindex.jpg") no-repeat center;' onclick='window.location="<?php bloginfo('url');?>/?page_id=35&city=san_francisco"' ><h1>San Francisco</h1></div></div>
		<div class="col-md-4 ftindex_gridelem" ><div class="ftindex_imgs" style='background: url("<?php bloginfo('template_directory');?>/images/SP_ftindex.jpg") no-repeat center;' onclick='window.location="<?php bloginfo('url');?>/?page_id=35&city=saint_petersburg"'><h1>Saint Petersbourg</h1></div></div>
		<div class="col-md-4 ftindex_gridelem" ><div class="ftindex_imgs" style='background: url("<?php bloginfo('template_directory');?>/images/ist_ftindex.jpg") no-repeat center;' onclick='window.location="<?php bloginfo('url');?>/?page_id=35&city=istanbul"'><h1>Istanbul</h1></div></div>
	</div>
</div>

<?php get_footer() ?>
