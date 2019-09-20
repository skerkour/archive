<?php
	$the_query = new WP_Query(array('locatin' => 'bruxelles'));
	if ($the_query->have_posts()) {
		echo '<ul>';
		while ($the_query->have_posts()) {
			$the_query->the_post();
			echo '<li>'.get_the_title().'</li>';
		}
		echo '</ul>';
	}
	else {
		echo 'no result found';
	}

		echo salut;
?>
