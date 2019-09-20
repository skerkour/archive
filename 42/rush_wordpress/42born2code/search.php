<?php get_header() ?>
<div id="content">
	<h2 class="tag-page-title"><?php _e( 'Resultat de la recherche pour:', 'wpbx' ) ?> <span><?php the_search_query() ?></span></h2>
	<!-- Begin loop -->
	<?php if ( have_posts() ) : ?>
	<?php while ( have_posts() ) : the_post() ?>
	<div class="entry">
		<div class="entry-top">
		<h2 class="entry-title"><a href="<?php the_permalink() ?>" title="<?php printf( __('Permalink to %s', 'wpbx'), the_title_attribute('echo=0') ) ?>" rel="bookmark"><?php the_title() ?></a></h2>
			<div class="entry-meta-top">
				<span class="entry-date"><?php unset($previousday); printf( __( '%1$s', 'wpbx' ), the_date( 'D, j M Y', '', '', false ) ) ?></span>
			</div>
		</div>
		<div class="entry-content clearfix">
			<div class= "entry-list-thumb">
				<a href="<?php the_permalink(); ?>" title="<?php printf(__( 'Read %s', 'wpbx' ), wp_specialchars(get_the_title(), 1)) ?>">
					<?php the_post_thumbnail(); ?>
				</a>
			</div>
			<div class="entry-content">
			<?php the_excerpt(); ?>
			</div>
		</div>
		<div class="entry-meta">	
			<span class="entry-meta-sep"></span>
			<span style="font-weight: bold;font-size:1.5em;"><a href="<?php the_permalink() ?>" title="<?php printf(__('Continue reading %s'), wp_specialchars(get_the_title(), 1)) ?>"><?php _e( 'Lire plus', 'wpbx' ) ?></a></span>
		</div>
	</div><!-- .post -->
<?php endwhile; ?>	<!-- End loop -->
<?php else : ?>
	<div class="entry post no-results not-found">
		<h3 class="entry-title"><?php _e( 'Oups pas de resultat !!!', 'wpbx' ) ?></h3>
			<div class="entry-content">
				<p><?php _e( 'Desole aucun resulat. Veuillez reesayer ici.', 'wpbx' ) ?></p>
				<form id="no" class="blog-search form-inline" method="get" action="<?php bloginfo('home') ?>">
					<input id="searchbox" class="form-control" name="s" type="text" placeholder="rechercher" tabindex="1" />
					<button type="submit" class="btn btn-primary" >Go!</button>
				</form>
			</div>
	</div><!-- .post -->
<?php endif; ?>
	<div class="navigation clearfix">
		<div class="nav-previous"><?php next_posts_link(__( 'Precedent <span class="meta-nav">Articles</span>', 'wpbx' )) ?></div>
		<div class="nav-next"><?php previous_posts_link(__( 'Suivant <span class="meta-nav">Articles</span>', 'wpbx' )) ?></div>
	</div>
</div><!-- #content -->
<?php /* get_sidebar() */ ?>
<?php get_footer() ?>
