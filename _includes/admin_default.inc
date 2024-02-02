
<ul class="list-dashboard-menu grid-system">
    
    <?php if (isset($_SESSION['auth']) && $_SESSION['type'] == 6): ?>
        <li><a class="icon icon-atop i-config-superadmin" href="?p=2"><span>ADMIN</span></a></li>
    <?php endif ?>
    <li><a class="icon icon-atop i-config-link" href="?p=3"><span>Liens URLs</span></a></li>
    <li><a class="icon icon-atop i-config-club" href="?p=5"><span>Infos club</span></a></li>
    <li><a class="icon icon-atop i-config-home" href="?p=4"><span>Page accueil</span></a></li>
    <li><a class="icon icon-atop i-news-add" href="?p=10"><span>Ajouter une actualité</span></a></li>
    <li><a class="icon icon-atop i-news" href="?p=11"><span>Gérer les actualités</span></a></li>
    <li><a class="icon icon-atop i-doc-add" href="?p=30"><span>Ajouter un document</span></a></li>
    <li><a class="icon icon-atop i-doc" href="?p=31"><span>Gérer les documents</span></a></li>

</ul>