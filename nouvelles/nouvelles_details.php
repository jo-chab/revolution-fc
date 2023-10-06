<?php	include("../_includes/session_test.inc");	include("../_includes/_revolutionfc.inc");?><!doctype html><html lang="fr"><head><meta charset="UTF-8" /><?php	if (isset($_GET['actu'])) 	{        $actu=$_GET['actu'];        $stmt = $db->prepare('select * from ACTUALITE, ACTUALITE_SECTION where id_actu = ? and id_section = id_actu_section');        $stmt->execute([$actu]);		while ($row = $stmt->fetch())		{			extract($row);            setlocale(LC_TIME, "fr_FR");			$url='https://www.revolutionfc.ca/nouvelles/nouvelles_details.php?actu='.$_GET['actu'];			$titre=nl2br(stripslashes($titre));			$intro=nl2br(stripslashes($intro));			$photo_fb='https://www.revolutionfc.ca/'.$photo;			$date = date('Y-m-d',strtotime($date_actu));			$date_text = strftime("%d %B %G", strtotime($date));			$date_text=nl2br(stripslashes(utf8_encode($date_text)));            $text=nl2br(stripslashes($texte));            $text = str_replace("<br />", "", $text);			$section=nl2br(stripslashes($section_name));		}	}?><title><?php echo $titre ?></title><meta name="description" content="<?php echo $intro ?>" /><meta name="viewport" content="width=device-width, initial-scale=1" /><!--remove pinterest--><meta name="pinterest" content="nopin" />        <link rel="icon" sizes="48x48" href="/assets/favicon-48x48.png"><link rel="icon" sizes="96x96" href="/assets/favicon-96x96.png"><link rel="icon" sizes="144x144" href="/assets/favicon-144x144.png"><link rel="icon" sizes="192x192" href="/assets/favicon-192x192.png"><link rel="icon" sizes="240x240" href="/assets/favicon-240x240.png">    <link rel="apple-touch-icon" sizes="240x240" href="/assets/favicon-240x240.png"><link rel="shortcut icon" href="/assets/favicon-192x192.png">	<!-- Open Graph data --><meta property="og:url"				content="<?php echo $url ?>" /><meta property="og:type"			content="article" /><meta property="og:title"			content="<?php echo $titre ?>" /><meta property="og:description" 	content="<?php echo $intro ?>" /><meta property="og:image"			content="<?php echo $photo_fb ?>" /><link rel="stylesheet" type="text/css" href="/assets/css/global.css"><script src="https://kit.fontawesome.com/bc60e60ac6.js" crossorigin="anonymous"></script><!--FONTS settings--><link rel="preconnect" href="https://fonts.googleapis.com"><link rel="preconnect" href="https://fonts.gstatic.com" crossorigin><link href="https://fonts.googleapis.com/css2?family=Poppins:ital,wght@0,400;0,500;0,600;0,700;0,800;1,400;1,500;1,700;1,800&family=Source+Sans+3:ital,wght@0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,300;1,400;1,700&display=swap" rel="stylesheet">    <!-- JQUERY --><script src="https://code.jquery.com/jquery-3.6.0.min.js"></script></head><body>			<?php	include("../_includes/header.inc");?><section>    <article class="wrapper-text">        <div class="article-heading">            <div class='article-info'>                <div class='news-category'><?php echo $section ?></div>                <h5 class="text-dates"><?php echo $date_text ?></h5>            </div>            <h1 class='article-title'><?php echo $titre ?></h1>            <p class='article-intro'><?php echo $intro ?></p>        </div>        <div class="article-featured-img">            <img src="/<?php echo $photo ?>" alt="" width="" height="" />        </div>        <div class="article-detail">                        <?php                $general_lines = explode("\n", stripslashes($text));                foreach ($general_lines as $line) {                    if (!empty(trim($line))) {                        echo "$line";                    }                }            ?>                    </div>        <div class='article-footer'>            <a class='btn-primary cta-back' href='javascript:history.go(-1)'>Retour</a>        </div>    </article></section>		<?php include("../_includes/footer.inc") ?>