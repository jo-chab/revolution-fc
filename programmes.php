<?php	include("_includes/session_test.inc");	include("_includes/_revolutionfc.inc");?><!doctype html><html><head><meta charset="UTF-8"><title>RFC - Nos programmes</title><?php	include("_includes/head.inc");    echo "<body>";	include("_includes/header.inc");?><section class="test">		<article class="grid-layout col-2 programme-container">        <?php        $stmt = $db->prepare('SELECT * from PROGRAMS order by id_program ASC');        $stmt->execute();        $results = $stmt->fetchAll(PDO::FETCH_ASSOC);        foreach ($results as $result)        {            $image=$result['program_img'];            $programme=$result['id_program'];            $title=nl2br(stripslashes($result['program_name']));            $intro=nl2br(stripslashes($result['program_intro']));            echo "            <a href='programme-detail.php?prog=$programme' class='programme-element test' id='programme-$programme'>                <div class='programme-img' style='background-image:url($image)'></div>                <h2>$title</h2>                <p class='intro'>$intro</p>                <div class='btn-tertiary btn-text'>En savoir plus</div>            </a>            ";        }        ?>			</article>	</section><!--    <script type="text/javascript">--><!--        $('.click-el').click(function() {--><!--            $parent = $(this).parent().attr("id");--><!--            $string = 'popup-';--><!--            $element = $string + $parent;--><!--            $('#' + $element).removeClass('is-hide');--><!--        });--><!--        $('.popup-btn').click(function() {--><!--            $(this).parent().addClass('is-hide');--><!--        });--><!----><!--    </script>-->	<?php include("_includes/footer.inc") ?>