

    // Fonction pour basculer la classe "is-hidden" des formulaires de la page login
    function toggleFormVisibility(formId) {
        const loginForm = document.getElementById("login-form");
        const registerForm = document.getElementById("register-form");

        if (formId === "show-login-popup") {
            loginForm.classList.remove("is-hidden");
            registerForm.classList.add("is-hidden");
        } else if (formId === "show-register-popup") {
            loginForm.classList.add("is-hidden");
            registerForm.classList.remove("is-hidden");
        }
    }

    // Écouteurs d'événements pour les liens <a>
    document.getElementById("show-login-popup").addEventListener("click", function (e) {
        e.preventDefault();
        toggleFormVisibility("show-login-popup");
    });

    document.getElementById("show-register-popup").addEventListener("click", function (e) {
        e.preventDefault();
        toggleFormVisibility("show-register-popup");
    });




    var closeAlertBox = document.getElementById("close-alert-box");
    var alertMessage = document.querySelector(".w-alert-message");
    closeAlertBox.addEventListener("click", function() {
        console.log('This is a test');
        alertMessage.style.display = "none";
    });