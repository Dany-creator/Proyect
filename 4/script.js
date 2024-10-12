document.getElementById('play-pause-button').addEventListener('click', function () {
    const button = document.getElementById('play-pause-button');
    if (button.classList.contains('play-button')) {
        button.classList.remove('play-button');
        button.classList.add('pause-button');
    } else {
        button.classList.remove('pause-button');
        button.classList.add('play-button');
    }
});
