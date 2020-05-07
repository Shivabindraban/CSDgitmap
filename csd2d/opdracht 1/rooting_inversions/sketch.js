var mode; // Check game screen
var introtextsize = 20;
let timer = 16;
// let timer = 2;
let polySynth = new p5.PolySynth();
let MIDInote = 60;
let clrbox1 = 150;
let clrbox2 = 150;
let counter = 0;
let totalcount = 0;

omkeringlijst=[0,0];
omkeringlijst1=[0,1];
omkeringlijst2=[1,1];


originalRootnote = 60;
rootnote = 60;
chordlist=[0,0,0];
first= [0,4,11];
second=[2,5,12];
fifth=[7,11,18];

omkeringlijst=[0,0];
omkeringlijst1=[0,1];
omkeringlijst2=[1,1];

function preload() {
  soundFormats('mp3','ogg');
  soundtrack = loadSound('Samples/Novabeatdryat80.mp3');
}

function setup() {
  //plaats hier de code die maar één keer hoeft te worden uitgevoerd
  frameRate(80);
  mode = 0;
  createCanvas(800,600);
  background(150);
}

function draw() {
  //plaats hier de code die continue herhaald moet worden.
  clear();
  if (mode==0){
    background(255);
    // textSize(introtextsize);
    text("Hi! Welcome to your Online Tool!",20,introtextsize);
    text("In this tool you will learn te importance of the use of inverses for chords.",20,2*introtextsize);
    text("Every upcoming chord, you have to choose how it will be played.",20,3*introtextsize);
    text("Enjoy and feel the music!",20,4*introtextsize);
    text("Press ENTER to start!",20,6*introtextsize);
  }
  if (mode==1){ //this can be seen as the new draw loop scene
    background(0);
    textAlign(CENTER, CENTER);
    textSize(100);
    fill(255);
    text(timer, width/2, height/2);
    if (frameCount % 45 == 0 && timer > 0) { // if the frameCount is divisible by 60, then a second has passed. it will stop at 0
      timer --;
    }
    if (timer == 0) {
      text(timer, width/2, height/2);
      text("Let's GO", width/2, height*0.7);
      background(255);

      fill(clrbox1,80,30);
      rect(width/10,height/10,width/3,height/2);
      fill(clrbox2,50,90);
      rect((width/2)+(width/10),height/10,width/3,height/2);
      fill(0);
      textSize(20);
      text('Click anywhere on the white screen for the original chord',width/2, (height - height/10) )
      text('Click here for inversion 1',width/4, height/3 )
      text('Click here for inversion 2',(width/2)+(width/4), height/3 )

      if (frameCount % 45 == 0){
        dur=0.3;
        vel=0.1;
        totalcount=counter

        if (totalcount == 0){
          rootnote=originalRootnote
          chordlist = second;
        }
        if (totalcount == 2){
          rootnote=originalRootnote
          chordlist = fifth;
        }
        if (totalcount == 4){
          rootnote=originalRootnote + random(8)
          chordlist = second;
        }
        if (totalcount == 6){
          chordlist = fifth;
        }
        if (totalcount == 8){
          rootnote=originalRootnote + random(8)
          chordlist = second;
        }
        if (totalcount == 10){
          chordlist = fifth;
        }
        if (totalcount == 12){
          rootnote=originalRootnote
          chordlist = first;
        }
        if (totalcount == 16){
          counter = 0;
        }

        polySynth.play(midiToFreq(rootnote+chordlist[0]), vel, 0, dur);
        polySynth.play(midiToFreq((rootnote+chordlist[1])-12*omkeringlijst[0]), vel, 0, dur);
        polySynth.play(midiToFreq((rootnote+chordlist[2])-12*omkeringlijst[1]), vel, 0, dur);
        console.log(omkeringlijst + ' eind')
        counter+=1
        console.log(totalcount)
      };
    };
  }
};

function mousePressed() {
  if (mouseX > (width/10) &&
    mouseX < ((width/3) + (width/10)) &&
    mouseY > (height/10) &&
    mouseY < ((height/2) + (height/10)) &&
    mouseIsPressed) {
      omkeringlijst=omkeringlijst1
      // clrbox1 = 80;
      // fill(clrbox1,80,30);
      // rect(width/10,height/10,width/3,height/2);
      // millis(50);
      // clrbox1 = 150;
      // fill(clrbox1,80,30);
      // rect(width/10,height/10,width/3,height/2);
      // console.log("Box one is Clicked");
      omkeringlijst=omkeringlijst1
      console.log(omkeringlijst)
  }
  else if (mouseX > (width/2)+(width/10) &&
    mouseX < ((width/2)+(width/10) + (width/3)) &&
    mouseY > (height/10) &&
    mouseY < ((height/2) + (height/10)) &&
    mouseIsPressed) {
      omkeringlijst=omkeringlijst2
      // clrbox2 = 80;
      // fill(clrbox2,50,90);
      // rect((width/2)+(width/10),height/10,width/3,height/2);
      // millis(50);
      // clrbox2 = 150;
      // fill(clrbox2,50,90);
      // rect((width/2)+(width/10),height/10,width/3,height/2);
      // console.log("Box two is Clicked");
      console.log(omkeringlijst)
  }
  else{
    omkeringlijst=[0,0];
  }
};

function keyPressed(){
  if (keyCode==ENTER){
    mode = 1;
    soundtrack.play();
  };
};
