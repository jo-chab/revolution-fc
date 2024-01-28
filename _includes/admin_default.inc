<div class='message-box maintenance'>
    <div class='icon i-alert'></div>
    <p>Il y a une maintenance en cours entre le 27 janvier 8:00 AM et dimanche 28 janvier 4:00 PM. Certaines fonctionalités seront limitées.<br/>Merci de votre patience</p>
</div>

<ul class="list-dashboard-menu grid-system">
    
    <?php if (isset($_SESSION['auth']) && $_SESSION['type'] == 6): ?>
        <li><a class="icon icon-atop i-config-superadmin" href="?p=2"><span>Config ADMIN</span></a></li>
    <?php endif ?>
    <li><a class="icon icon-atop i-config-site" href="?p=3"><span>Config website</span></a></li>
    <li><a class="icon icon-atop i-config-club" href="?p=5"><span>Config Infos club</span></a></li>
    <li><a class="icon icon-atop i-config-home" href="?p=4"><span>Config page accueil</span></a></li>
    <li><a class="icon icon-atop i-news-add" href="?p=10"><span>Ajouter une actualité</span></a></li>
    <li><a class="icon icon-atop i-news" href="?p=11"><span>Gérer les actualités</span></a></li>
    <li><a class="icon icon-atop i-doc-add" href="?p=30"><span>Ajouter un document</span></a></li>
    <li><a class="icon icon-atop i-doc" href="?p=31"><span>Gérer les documents</span></a></li>

</ul>