<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");?><!doctype html><html lang="fr"><head>    <meta charset="UTF-8">    <title>Révolution FC - Login</title>    <meta name="viewport" content="width=device-width, initial-scale=1">        <link rel="stylesheet" type="text/css" href="/assets/css/global_admin.css">    <link href="https://fonts.googleapis.com/css?family=Roboto+Condensed:300,400,700|Roboto:300,300i,400,400i,500"          rel="stylesheet">    <script src="https://kit.fontawesome.com/50775e0d2d.js" crossorigin="anonymous"></script>        <script src="https://www.google.com/recaptcha/api.js" async defer></script><body><section class="wrapper">        <?php include("../_includes/alert_messages.inc"); ?>        <article class="w-login">                <form class="popup" id="login-form" method="post" action="action-login-test">                        <h2 class="popup-title">Se connecter</h2>                        <div class="form-row column">                <label for="identifiant">Votre nom d'utilisateur</label>                <input type="text" name="zt_identifiant" id="identifiant" value=""/>            </div>                        <div class="form-row column">                <label for="password">Mot de passe</label>                <input type="password" name="zt_password" id="password" value=""/>            </div>                        <p class="popup-legend">Pas encore inscrit? <a class="inline-link" id="show-register-popup" href="">Cliquez ici</a></p>                        <input type="submit" class="cta-login" value="Se connecter"/>                </form>                <form class="popup is-hidden" id="register-form" method="post" action="action-login-register">                        <h2 class="popup-title">S'inscrire</h2>                        <p class="popup-legend">L'inscription en tant qu'utilisateur est <span>réservée pour les entraineurs et membres du personnel du club</span>                <br/>Si vous ne faites pas parti du club, votre enregistrement sera supprimé. Si vous désirez entrer en contact                avec le club merci d'utiliser le <a class="inline-link" href="../contact">formulaire de contact</a></p>                        <div class="form-row column">                <input type="text" name="zt_fn" id="first_name" value="" placeholder="Prénom" required/>            </div>                        <div class="form-row column">                <input type="text" name="zt_ln" id="last_name" value="" placeholder="Nom de famille" required/>            </div>                        <div class="form-row column">                <input type="text" name="zt_username" id="username" value="" placeholder="Nom d'utilisateur" required/>                <p class="popup-legend">Notez votre non d'utilisateur car c'est lui qui sera utilisé pour vous connecter !</p>            </div>                        <div class="form-row column">                <input type="email" name="zt_email" id="email" value="" placeholder="Adresse courriel" equired/>            </div>                        <div class="form-row column">                <input type="password" name="zt_new_pass" id="new_password" value="" placeholder="Mot de passe" required/>            </div>                        <div class="form-row column">                <input type="password" name="zt_new_pass_2" id="new_password_2" value="" placeholder="Confirmer mot de passe" required/>            </div>                        <div class="g-recaptcha" data-sitekey="6Lc8qswcAAAAAGwkQsMC9KUZbgLMiNJvU4mEKADT"></div>                        <input type="submit" name="submit" class="cta-login" value="Confirmer inscription">                        <p class="popup-legend" style="text-align: center; margin-top: 1rem;">Déjà inscrit? <a class="inline-link" id="show-login-popup" href="">Connectez-vous</a></p>                </form>                <a class='btn-primary cta-back' href='https://www.revolutionfc.ca/'>Retour au site</a>        </article></section><script type="text/javascript" src="/js/login.js"></script><script src="https://www.google.com/recaptcha/api.js" async defer></script><script type="text/javascript" src="/js/admin.js"></script></body></html>