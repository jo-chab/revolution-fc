<?php	include("_includes/session_test.inc");	include("_includes/_revolutionfc.inc");?><!doctype html><html lang="fr"><head><meta charset="UTF-8"><title>R&eacute;volution FC - Bienvenue</title><?php	include("_includes/head.inc");    echo "<body class='w-home'>";	include("_includes/header.inc");?><script type="text/javascript">$(document).ready(function () {        $( ".scroll-down" ).click(function( event ) {                var headerHeight = $('.top-header').outerHeight();                $("html, body").animate({                        scrollTop: $("#hp-news_list").offset().top                }, 500);        });});</script><!-- START OF THE HERO IMAGE SECTION --><section class="w-hero">    <article class="wrapper-full">        <div class="hero-img">            <figure>                <picture>                    <source media="(min-width: 768px)" srcset="img/hp-hero.jpg">                    <source media="(min-width: 0)" srcset="img/hp-hero-mobile.jpg">                    <img alt="Revolution FC" width="" height="" />                </picture>            </figure>            <div class="hero-overlay-gradient">                <div class="hero-overlay-content">                    <h1>Chaque jeune a sa place</h1>                    <a class="btn-secondary ghost-white" href="programmes.php">Découvrez nos programmes</a>                </div>            </div>        </div>    </article></section><!-- END OF THE HERO IMAGE SECTION --><!-- START OF THE LATEST NEWS SECTION --><section id="hp-news_list">	<article class="wrapper">        <h2>Derni&egrave;res nouvelles</h2>		<div class="news-container">			<?php                $stmt = $db->prepare('select * from ACTUALITE,ACTUALITE_SECTION where id_actu_section = id_section AND actif = 1 order by date_actu DESC LIMIT 4');                $stmt->execute();				$cpt2=0;                $news_number=3;                $results = $stmt->fetchAll(PDO::FETCH_ASSOC);                foreach($results as $result)                //while ($row = $stmt->fetch() and $cpt2<3)                {                    if($cpt2<$news_number)                    {                        setlocale (LC_TIME, 'fr_FR');                        $date = date('Y-m-d',strtotime($result['date_actu']));                        $date_text = strftime("%d %B %G", strtotime($date));                        $date_text=nl2br(stripslashes(utf8_encode($date_text)));                        $titre=nl2br(stripslashes($result['titre']));                        $bgImg=nl2br(stripslashes($result['photo']));                        $categorie=nl2br(stripslashes($result['section_name']));                        $id_actu=$result['id_actu'];                        $cpt2++;                        echo "<div class='news-card'>							<a href='nouvelles_details.php?actu=$id_actu'>								<div class='news-card-img' style='background-image:url($bgImg);'>								</div>								<div class='news-card-vignette'>								    <div class='news-card-info'>                                        <div class='news-category'>$categorie</div>									    <h6>$date_text</h6>                                    </div>                                    <h3 class='news-card-headline'>$titre</h3>								</div>							</a></div>";                    }				}			?>		</div>		<div class="btn-tertiary"><a href="nouvelles.php">D&eacute;couvrir toutes les actualit&eacute;s</a></div>	</article>    <article class="wrapper-text">        <div class="hp-jobs">            <ul>                <?php                $stmt2 = $db->prepare('select * from EMPLOIS order by id_job ASC');                $stmt2->execute();                $results2 = $stmt2->fetchAll(PDO::FETCH_ASSOC);                if (empty($results2)) {                    echo "                    <li>                        <h4>Il n'y a aucune offre d'emploi actuellement</h4>                    </li>";                }                else {                    foreach($results2 as $result2)                    {                        $titre=nl2br(stripslashes($result2['job_name']));                        $desc=nl2br(stripslashes($result2['job_desc']));                        $link=$result2['job_doc'];                        echo "                    <li>                        <div class='job-infos'>                            <h4>$titre</h4>                            <p>$desc</p>                        </div>                        <a class='btn-primary' href='$link' target='_blank'>Postuler</a>                    </li>";                    }                }                ?>            </ul>        </div>    </article></section><!-- START OF THE CONTACT SECTION --><section class="contact">	<article class="grid-layout col-2">			<div class="hp-google-map">                <iframe src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d2793.481378085122!2d-73.89852488415028!3d45.56075747910213!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x4cc92f8101231131%3A0x6d09ce0acaeaf77e!2s230%20Bd%20Arthur-Sauv%C3%A9%2C%20Saint-Eustache%2C%20QC%20J7R%202H9!5e0!3m2!1sfr!2sca!4v1632789393071!5m2!1sfr!2sca" width="100%" height="400" style="border:0;" allowfullscreen="" loading="lazy"></iframe>			</div>			<div class="hp-contact-info">                <div class="contact-info-details">                    <h4>Coordonn&eacute;es</h4>                    <p>230 Boulevard Arthur-Sauvé,<br/>Saint-Eustache, QC J7R 2H9</p>                    <p>T&eacute;l&eacute;phone :  (438) 389-0198</p>                    <p>Courriel : administration@revolutionfc.ca</p>                </div>                <div class="contact-info-details">                    <h4>Heures d'ouverture</h4>                    <p>Lundi : 10:00 - 18:00 (virtuel)                        <br/>Mardi : 10:00 - 18:00 (virtuel)                        <br/>Mercredi : 10:00 - 18:00 (virtuel)                        <br/>Jeudi : 10:00 - 18:00 (virtuel)                        <br/>Vendredi : ferm&eacute;                        <br/>Samedi : ferm&eacute;                        <br/>Dimanche : ferm&eacute;</p>                </div>			</div>	</article></section><!-- END OF THE CONTACT SECTION --><!-- START OF THE SPONSORS SECTION --><section style="background-color: white;">	<article class="wrapper">		<ul class="sponsors-list">			<?php                $stmt2 = $db->prepare('select * from SPONSORS where actif = 1 and is_club = 1 order by name_sponsors ASC');                $stmt2->execute();				$cpt3=0;				while ($row2 = $stmt2->fetch())				{					extract($row2);					$sponsors_name=nl2br(stripslashes($name));					$logo_sponsors=nl2br(stripslashes($logo_sponsors));					$url_sponsors=nl2br(stripslashes($url));					$cpt3++;					echo "<li class='sponsors-logo'><a href='$url_sponsors' target='_blank' rel='noreferrer'><img src='../$logo_sponsors' alt='$sponsors_name' /></a></li>";				}			?>		</ul>	</article></section><!-- END OF THE SPONSORS SECTION -->				<!--<script type="text/javascript">	$(document).ready(function() {	if(localStorage.getItem('popState') != 'shown'){		$(".popup").delay(800).fadeIn();		localStorage.setItem('popState','shown')	}	$('#popup-close').click(function(e) 	{		$('.popup').fadeOut();	});	$('.popup').click(function(e) 	{		$('.popup').fadeOut(); 	});});	</script>-->		<!-- POPUP WINDOW SECTION -->	<!--<section  class="popup" style="display: none;">		<article class="popup-container">			<div class="popup-window">				<h3 class="white">Message important!</h3>				<p>Les inscriptions pour la Camp de Jour de FSS sont en court. Plus d'informations en cliquant sur le lien du menu</p>				<div class="popup-btn" id="popup-close"><i class="far fa-times"></i> Fermer</div>			</div>		</article>	</section>--><!-- POPUP WINDOW SECTION --><?php	include("_includes/footer.inc");?>