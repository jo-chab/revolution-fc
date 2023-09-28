<div id="cookie-popup" class="cookie-popup">
    
    <h3 style="text-align: left">Utilisation des cookies</h3>
    <p>Nous utilisons des cookies pour améliorer votre expérience, gérer votre compte et faciliter la navigation sur les pages de notre site web.</p>
    <p class="legend">Voir notre <a class="inline-link" href="/panel/politique-confidentialite">Politique de confidentialité</a>.</p>
    <!--    <p>We use cookies to analyze website traffic and optimize your website experience. By accepting our use of cookies, your data will be aggregated with all other user data.</p>-->
    
    <div class="cookie-cta">
        <div id="decline-cookies" class="btn-tertiary btn-cancel icon">Declined</div>
        <div id="accept-cookies" class="btn-primary btn-brand icon i-check">Accept</div>
    </div>

</div>

<script>
    // Show the popup if the user has not accepted cookies before
    if (!localStorage.getItem('cookieConsent')) {
        document.getElementById('cookie-popup').style.display = 'flex';
    }

    // Handle user's choice to accept cookies
    document.getElementById('accept-cookies').addEventListener('click', function () {
        localStorage.setItem('cookieConsent', 'accepted');
        document.getElementById('cookie-popup').style.display = 'none';
    });

    // Handle user's choice to decline cookies (optional)
    document.getElementById('decline-cookies').addEventListener('click', function () {
        // You can add additional code here, e.g., disabling certain cookies.
        localStorage.setItem('cookieConsent', 'declined');
        document.getElementById('cookie-popup').style.display = 'none';
    });

</script>