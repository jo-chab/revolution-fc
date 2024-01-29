
<div class="username-title">Bonjour <span><?php echo $_SESSION['username']; ?></span></div>

<ul class="top-header">
    <li class="menu-toggle-admin nav-element icon only-mobile"><span>Menu</span></li>
    <li><a class="nav-element icon i-homepage icon-only" href="/" title="Accueil Site"><span>Accueil site</span></a></li>
    <li><a class="nav-element icon i-homepage-2 icon-only" href="/admin/index?p=1" title="Accueil Admin"><span>Accueil admin</span></a></li>
    <?php if (isset($_SESSION['auth']) && $_SESSION['type'] == 6): ?>
        <li class="only-tablet"><a class="nav-element icon i-bdd" href="https://hp341.servername.online:2083/cpsess5111029340/frontend/paper_lantern/sql/PhpMyAdmin.html" target="_blank"></a></li>
    <?php else : ?>
    <?php endif ?>
    <li><a class="nav-element icon i-logout icon-only" href="action-logout" title="Logout"></a></li>
</ul>


<ul class="sidebar-menu">
    <!--For testing purpose-->
    <?php if (isset($_SESSION['auth']) && $_SESSION['type'] == 6): ?>
    <?php endif ?>
    
    
    <li class="menu-element icon i-config">Configuration
        <ul class="sub-nav">
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=2">Config ADMIN – Jonathan</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=3">Config générale</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=4">Page d'accueil</a></li>
        </ul>
    </li>
    
    <li class="menu-element icon i-news">Actualités
        <ul class="sub-nav">
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="index.php?p=11">Gérer les actualités</a></li>
        </ul>
    </li>
    
    <li class="menu-element icon i-rfc-logo">Club
        <ul class="sub-nav">
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=5">Informations générales</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=31">Gérer les documents</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=33">Gérer les catégories de documents</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=301">Gérer les offres d'emplois</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=61">Gérer les Terrains</a></li>
        </ul>
    </li>
    
    <li class="menu-element icon i-user">Personnes
        <ul class="sub-nav">
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=21">Membres du CA</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=23">Membres de l'administration</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=25">Membres du staff technique</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=93">Gérer les Utlisateurs</a></li>
        </ul>
    </li>
    
    <li class="menu-element icon i-soccer-1">Technique
        <ul class="sub-nav">
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=51">Gérer les Programmes</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=35">Gérer les Documents technique</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=37">Gérer les catégories technique</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=38">Gérer les sous-catégories technique</a></li>
        </ul>
    </li>
    
    <li class="menu-element icon i-tournament">Tournois
        <ul class="sub-nav">
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=81">Gérer les tournois</a></li>
        </ul>
    </li>
    
    <li class="menu-element icon i-events"><span class="icon new-feature">Evenements</span>
        <ul class="sub-nav">
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=63">Gérer les évènements</a></li>
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=64">Créer un évènement</a></li>
        </ul>
    </li>
    
    <li class="menu-element icon i-sponsors">Sponsors
        <ul class="sub-nav">
            <li class="sub-nav-item"><a class="sub-nav-item-el" href="?p=91">Gérer les sponsors</a></li>
        </ul>
    </li>
</ul>