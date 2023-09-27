

$(document).ready(function () {

    'use strict';

    // Fonction pour ouvrir le menu au clic
    $('.menu-toggle').click(function(){
        $('.desktop').toggleClass('open');
    });

    //Fonction qui ajoute l'icone quand il y a un sous-menu
    $('.nav-item').each(function() {
        if ($(this).next().is('.sub-nav')) {
            $(this).addClass('arrowed');
        } else {};
    });


    //Fonction qui ajoute la classe SELECTED quand on clique et qui active ou desactive le sous-menu
    $('.arrowed').click(function() {
        $(this).toggleClass('selected');
        $(this).siblings().removeClass("selected");
        $('.sub-nav').each(function() {
            $(this).slideUp("900");
        });
        if ($(this).next('.sub-nav').is(':visible')) {
            $(this).next('.sub-nav').slideUp('900');
        } else {
            $(this).next('.sub-nav').slideDown('900');
        };
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

