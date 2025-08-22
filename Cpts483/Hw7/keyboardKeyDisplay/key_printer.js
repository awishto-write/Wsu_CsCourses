//local variable usedto reduce code size
const keyMap = {
    "KeyW": "imageW",     // W key
    "KeyA": "imageA",     // A key
    "KeyS": "imageS",     // S key
    "KeyD": "imageD",     // D key
    "KeyQ": "imageQ",     // Q key
    "KeyE": "imageE",     // E key
    "KeyC": "imageC",     // C key
    "Space": "imageSpace", // Space key
    "ArrowUp": "imageUp",    // Up arrow key
    "ArrowDown": "imageDown",  // Down arrow key
    "ArrowLeft": "imageLeft",  // Left arrow key
    "ArrowRight": "imageRight"  // Right arrow key
};

//this goes in the added container hook so that the html doesn't get crowded
var content = "<img id='imageW' src='./keyboardKeyDisplay/keyboard_key_w.png' class='overlay-imageW' alt='didnt work'>\
<img id='imageA' src='./keyboardKeyDisplay/keyboard_key_a.png' class='overlay-imageA' alt='didnt work'>\
<img id='imageS' src='./keyboardKeyDisplay/keyboard_key_s.png' class='overlay-imageS' alt='didnt work'>\
<img id='imageD' src='./keyboardKeyDisplay/keyboard_key_d.png' class='overlay-imageD' alt='didnt work'>\
<img id='imageQ' src='./keyboardKeyDisplay/keyboard_key_q.png' class='overlay-imageQ' alt='didnt work'>\
<img id='imageE' src='./keyboardKeyDisplay/keyboard_key_e.png' class='overlay-imageE' alt='didnt work'>\
<img id='imageC' src='./keyboardKeyDisplay/keyboard_key_c.png' class='overlay-imageC' alt='didnt work'>\
<img id='imageSpace' src='./keyboardKeyDisplay/keyboard_key_space.png' class='overlay-imageSpace' alt='didnt work'>\
<img id='imageUp' src='./keyboardKeyDisplay/keyboard_key_up.png' class='overlay-imageUp' alt='didnt work'>\
<img id='imageDown' src='./keyboardKeyDisplay/keyboard_key_down.png' class='overlay-imageDown' alt='didnt work'>\
<img id='imageLeft' src='./keyboardKeyDisplay/keyboard_key_left.png' class='overlay-imageLeft' alt='didnt work'>\
<img id='imageRight' src='./keyboardKeyDisplay/keyboard_key_right.png' class='overlay-imageRight' alt='didnt work'></img>";

//Find the target div by its id
var targetDiv = document.getElementById("imageIDs");

//Insert the content into the target div
targetDiv.innerHTML = content;

//Add two more event listeners so that it doesn't mess with the openGL code
addEventListener( 'keydown', function( ev ) {
    if( typeof ev.code === 'string' ) {
        print_keys(ev,"block");
    }
})
addEventListener( 'keyup', function( ev ) {
    if( typeof ev.code === 'string' ) {
        print_keys(ev,"none");
        
    }
})

//Display the key when pressed, use hard coded location from imageDisplay.css
function print_keys(ev,imageDisplayString) {

    if(keyMap[ev.code]){
        const image = document.getElementById(keyMap[ev.code]);
        if(image){
            image.style.display = imageDisplayString;
        }
    }
}