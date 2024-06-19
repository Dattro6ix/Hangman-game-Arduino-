#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define ALPHABET_SIZE 26

const int nextButton = 3;
const int previousButton = 2;
const int selectButton = 1;
const int RedLedPin = 13;
const int GreenLedPin = 12;
int nextButtonState = 0;
int previousButtonState = 0;
int selectButtonState = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char selectedLetters[ALPHABET_SIZE]; 
int randNumber = 0;
int selectedCount = 0;
int alphabetcount = 0;
bool letterInWord = false;
int wrongGuessCount = 0;
char words[][10] = {"APPLE", "BANANA", "CHERRY", "CHICKEN", "ELEPHANT", "DOG", "RAT","ORANGE", "BASEBALL", "HOSPITAL"}; 

void displayCharacters(byte firstChar[], byte secondChar[], byte thirdChar[], byte fourthChar[]) {
  lcd.createChar(3, firstChar);
  lcd.createChar(4, secondChar);
  lcd.createChar(5, thirdChar);
  lcd.createChar(6, fourthChar);

  lcd.home();
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(0, 1);
  lcd.write(5);
  lcd.write(6);
}

void displayHangman() {
  switch (wrongGuessCount) {
    case 0:
      displayPole();
      break;
    case 1:
      displayHead();
      break;
    case 2:
      displayBody();
      break;
    case 3:
      displayRightArm();
      break;
    case 4:
      displayLeftArm();
      break;
    case 5:
      displayRightLeg();
      break;
    case 6:
      displayLeftLeg();
      break;
    case 7:
      displayFace();
      break;
  }
}

void displayPole(){
  byte firstChar[] = {B11111, B10000, B10000, B10000, B10000, B10000, B10000, B10000};
  byte secondChar[] = {B10000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
  byte thirdChar[] = {B10000, B10000, B10000, B10000, B10000, B10000, B10000, B11111};
  byte fourthChar[] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B11111};

  displayCharacters(firstChar, secondChar, thirdChar, fourthChar);
}

void displayHead(){
  byte firstChar[] = {B11111, B10001, B10010, B10100, B10100, B10100, B10010, B10001};
  byte secondChar[] = {B10000, B11000, B00100, B00010, B00010, B00010, B00100, B11000};
  byte thirdChar[] = {B10000, B10000, B10000, B10000, B10000, B10000, B10000, B11111};
  byte fourthChar[] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B11111};

  displayCharacters(firstChar, secondChar, thirdChar, fourthChar);
}
void displayBody(){
  byte firstChar[] = {B11111, B10001, B10010, B10100, B10100, B10100, B10010, B10001};
  byte secondChar[] = {B10000, B11000, B00100, B00010, B00010, B00010, B00100, B11000};
  byte thirdChar[] = {B10000, B10000, B10000, B10000, B10000, B10000, B10000, B11111};
  byte fourthChar[] = {B10000, B10000, B10000, B10000, B10000, B00000, B00000, B11111};

  displayCharacters(firstChar, secondChar, thirdChar, fourthChar);
}
void displayRightArm(){
  byte firstChar[] = {B11111, B10001, B10010, B10100, B10100, B10100, B10010, B10001};
  byte secondChar[] = {B10000, B11000, B00100, B00010, B00010, B00010, B00100, B11000};
  byte thirdChar[] = {B10000, B10000, B10000, B10000, B10000, B10000, B10000, B11111};
  byte fourthChar[] = {B11000, B10100, B10010, B10001, B10000, B00000, B00000, B11111};

  displayCharacters(firstChar, secondChar, thirdChar, fourthChar);
}
void displayLeftArm(){
  byte firstChar[] = {B11111, B10001, B10010, B10100, B10100, B10100, B10010, B10001};
  byte secondChar[] = {B10000, B11000, B00100, B00010, B00010, B00010, B00100, B11000};
  byte thirdChar[] = {B10001, B10010, B10100, B11000, B10000, B10000, B10000, B11111};
  byte fourthChar[] = {B11000, B10100, B10010, B10001, B10000, B00000, B00000, B11111};

  displayCharacters(firstChar, secondChar, thirdChar, fourthChar);
}
void displayRightLeg(){
  byte firstChar[] = {B11111, B10001, B10010, B10100, B10100, B10100, B10010, B10001};
  byte secondChar[] = {B10000, B11000, B00100, B00010, B00010, B00010, B00100, B11000};
  byte thirdChar[] = {B10001, B10010, B10100, B11000, B10000, B10000, B10000, B11111};
  byte fourthChar[] = {B11000, B10100, B10010, B10001, B11000, B00100, B00010, B11111};

  displayCharacters(firstChar, secondChar, thirdChar, fourthChar);
}
void displayLeftLeg(){
  byte firstChar[] = {B11111, B10001, B10010, B10100, B10100, B10100, B10010, B10001};
  byte secondChar[] = {B10000, B11000, B00100, B00010, B00010, B00010, B00100, B11000};
  byte thirdChar[] = {B10001, B10010, B10100, B11000, B10001, B10010, B10100, B11111};
  byte fourthChar[] = {B11000, B10100, B10010, B10001, B11000, B00100, B00010, B11111};

  displayCharacters(firstChar, secondChar, thirdChar, fourthChar);
}
void displayFace() {
  byte firstChar[] = {B11111, B10001, B10010, B10101, B10100, B10101, B10010, B10001};
  byte secondChar[] = {B10000, B11000, B00100, B01010, B00010, B11010, B00100, B11000};
  byte thirdChar[] = {B10001, B10010, B10100, B11000, B10001, B10010, B10100, B11111};
  byte fourthChar[] = {B11000, B10100, B10010, B10001, B11000, B00100, B00010, B11111};

  displayCharacters(firstChar, secondChar, thirdChar, fourthChar);
}

void displayLetter() {
  lcd.clear(); 
  lcd.setCursor(14, 0); // Set cursor to the first line
  lcd.print(alphabet[alphabetcount]);
  lcd.setCursor(15, 0);
  if(alphabetcount+1 != 26){
    lcd.print(alphabet[alphabetcount+1]);
  }
  else if(alphabetcount+1 == 26){
    lcd.print(alphabet[0]);
  }
  lcd.setCursor(13, 0);
  if(alphabetcount-1 == -1){
    lcd.print(alphabet[25]);
  }
  else{
    lcd.print(alphabet[alphabetcount-1]);
  }
}

void displayArrows(){
  byte LeftArrow[] = { B00000, B00000, B00100, B01100, B11111, B01100, B00100, B00000 };
  byte RightArrow[] = { B00000, B00000, B00100, B00110, B11111, B00110, B00100, B00000 };
  byte circle[] = { B00000, B00000, B00100, B01110, B11111, B01110, B00100, B00000 };

  lcd.createChar(0, LeftArrow);
  lcd.createChar(1, RightArrow);
  lcd.createChar(2, circle);

  lcd.setCursor(13, 1);
  lcd.write(0);
  lcd.setCursor(14, 1); 
  lcd.write(2);
  lcd.setCursor(15, 1);
  lcd.write(1);
}

void addToListLetters(char selectedLetter) {
    // Check if the letter is not already in the list
    if (selectedCount < ALPHABET_SIZE) {
        bool letterExists = false;
        for (int i = 0; i < selectedCount; i++) {
            if (selectedLetters[i] == selectedLetter) {
                letterExists = true;
                break;
            }
        }

        // If the letter is not in the list of letters picked, add it
        if (!letterExists) {
            selectedLetters[selectedCount] = selectedLetter;
            selectedCount++;
            // Turn on the LED when a letter is added to the list
            digitalWrite(GreenLedPin, HIGH);
            delay(500); 
            digitalWrite(GreenLedPin, LOW);

            // Check if the letter is in the word
            checkIfLetterInWord(selectedLetter);
            if (letterInWord == false) {
              wrongGuessCount++;     //word increment the wrong guess count if letter is not in word
            }
        }
        else{
          digitalWrite(RedLedPin, HIGH);
          delay(500); 
          digitalWrite(RedLedPin, LOW);
        }
    }
}

void printSelectedLetters() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selected Letters:");
  
  for (int i = 0; i < selectedCount; i++) {
    lcd.setCursor(i, 1);
    lcd.print(selectedLetters[i]);
  }
}

char wordDisplay[10]; // Array to store the displayed word

void initializeWordDisplay() {
  int wordLength = strlen(words[randNumber]);
  for (int i = 0; i < wordLength; i++) {
    wordDisplay[i] = '_';
  }
  wordDisplay[wordLength] = '\0';
}

void displayWord() {
  lcd.setCursor(3, 0);
  lcd.print(wordDisplay);
}

void displayLetterInWord(int index, char selectedLetter) {
  wordDisplay[index] = selectedLetter;
  displayWord();
}

void checkIfLetterInWord(char selectedLetter) {
  int wordLength = strlen(words[randNumber]);
  // Check if the selected letter is in the word
  letterInWord = false; //resets
  for (int i = 0; i < wordLength; i++) {
    if (words[randNumber][i] == selectedLetter) {
      letterInWord = true;
      displayLetterInWord(i, selectedLetter);
    }
  }
}
boolean WordGuessed() {
  int wordLength = strlen(words[randNumber]);
  for (int i = 0; i < wordLength; i++) {
    if (wordDisplay[i] == '_') {
      return false; // "_" means that there is a letter that is not guessed
    }
  }
  return true; //if there is no "_" in the string that means all the letters are guessed
}

void resetGame() {
  //pick a new word
  randomSeed(analogRead(0));
  randNumber = random(0, 9);

  //reset everything
  alphabetcount = 0;
  selectedCount = 0;
  wrongGuessCount = 0;
  letterInWord = false;
  initializeWordDisplay();
  lcd.clear();
  displayLetter();
  displayArrows();
  displayWord();
  displayHangman();
}

void setup() {
  randomSeed(analogRead(0));
  randNumber = random(0, 5);
  lcd.begin();
  displayLetter();
  initializeWordDisplay();
  displayWord();
  displayArrows();
  displayHangman();
}

void loop() {
  nextButtonState = digitalRead(nextButton);
  if (nextButtonState == HIGH) {
    alphabetcount++;
    delay(200);
    if (alphabetcount == 26) {
      alphabetcount = 0;
    }
    displayLetter();
    displayArrows();
    displayWord();
    displayHangman();
  }

  previousButtonState = digitalRead(previousButton);
  if (previousButtonState == HIGH) {
    alphabetcount--;
    delay(200);
    if (alphabetcount == -1) {
      alphabetcount = 25;
    }
    displayLetter();
    displayArrows();
    displayWord();
    displayHangman();
  }

  selectButtonState = digitalRead(selectButton);
  if (selectButtonState == HIGH) {
    char selectedLetter = alphabet[alphabetcount];
    delay(500);
    addToListLetters(selectedLetter);
    printSelectedLetters();
    delay(1000);
    checkIfLetterInWord(selectedLetter);
    displayLetter();
    displayArrows();
    displayWord();
    displayHangman();
  }
  if (wrongGuessCount == 8) {
    // End the game
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game Over!");
    
    for (int i = 5; i > 0; i--) {
        lcd.setCursor(0, 1);
        lcd.print("Restart in: " + String(i));
        delay(1000);
    }

    // Reset the game
    resetGame();
  }
  if(WordGuessed() == true){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Congratulations!");
    
    for (int i = 5; i > 0; i--) {
        lcd.setCursor(0, 1);
        lcd.print("Restart in: " + String(i));
        delay(1000);
    }

    // Reset the game
    resetGame();
  }
}