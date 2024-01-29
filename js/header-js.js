

$(document).ready(function () {

    'use strict';

    var currentScrollTop = 0;
    var navbar = $('.top-header');
    var c = 0; // Initialize the "c" variable

    var heroHeight = $('.hp-hero').outerHeight();

    $(window).scroll(function () {
        var a = $(window).scrollTop();
        var b = navbar.height();

        currentScrollTop = a;

        if (c < currentScrollTop && a > b + b) {
            navbar.addClass("small");
        } else if (c > currentScrollTop && !(a <= b)) {
            navbar.removeClass("small");
        }
        c = currentScrollTop;

    });

    // Fonction pour ouvrir le menu au clic
    $('.menu-toggle').click(function(){
        $('.desktop').toggleClass('open');
    });

    //Fonction qui ajoute l'icone quand il y a un sous-menu
    $('.nav-item').each(function() {
        if ($(this).next().is('.sub-nav')) {
            $(this).addClass('arrowed');
        } else {}
    });


    //Fonction qui ajoute la classe SELECTED quand on clique et qui active ou desactive le sous-menu
    $('.arrowed').click(function() {
        $(this).toggleClass('selected');
        $(this).siblings().removeClass("selected");
        var subNav = $(this).next('.sub-nav');
        $('.sub-nav').not(subNav).slideUp('400');
        subNav.slideToggle('400');
    });

    $(".close-alert-box").click(function(){
        $(".w-alert-message").hide();
    });

});

/* Fonction qui ferme le menu lorsque l'on appuie sur ESC */
$(document).keyup(function(e) {
    if (e.keyCode === 27) {
        $('nav').removeClass('open');
    }
});

