const int RED = 11; // пін червоної ноги RGB-світлодіоди
const int GREEN = 9; // пін зеленої ноги RGB-світлодіоди
const int BLUE = 10; // пін синьої ноги RGB-світлодіоди

//масиви для кольорів
int cur[3] = {0, 0, 0};
int blue[3] = {0, 0, 255};
int orange[3] = {255, 125, 0};
int viola[3] = {255, 0, 255};
int green[3] = {0, 255, 0};
int yellow[3] = {255, 255, 0};
int red[3] = {255, 0, 0};
int sky[3] = {0, 255, 255};


void setup(){
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(9600);
}

//функція порівняння масивів
bool equal(int *arr1, int *arr2){
  if(arr1[0] != arr2[0]){ //порівнюємо перші елементи, якщо відрізняються
    return false;         //повертаємо false
  }else if(arr1[1] != arr2[1]){ //порівнюємо другі елементи, якщо відрізняються
    return false;               //повертаємо false
  }else if(arr1[2] != arr2[2]){ //порівнюємо треті елементи, якщо відрізняються
    return false;               //повертаємо false
  }else{
    return true;  //інакше повертаємо true
  }
}

//функція плавної зміни кольорів
void changer(int *arr){
  while (!equal(cur, arr)){ //виконуємо поки бажаний масив не дорівнює поточному
    if(cur[0] != arr[0]) //порівнюємо перші елементи, якщо відрізняються
      cur[0] += (arr[0]-cur[0])/fabs(arr[0]-cur[0]); //додаємо або віднімаємо одиницю
                                                    //fabs потрібен для збереження знаку різниці
    Serial.print("R: ");
    Serial.print(cur[0]);
    if(cur[1] != arr[1]) //порівнюємо другі елементи, якщо відрізняються
      cur[1] += (arr[1]-cur[1])/fabs(arr[1]-cur[1]); //додаємо або віднімаємо одиницю
                                                    //fabs потрібен для збереження знаку різниці
    Serial.print(" G: ");
    Serial.print(cur[1]);
    if(cur[2] != arr[2]) //порівнюємо треті елементи, якщо відрізняються
      cur[2] += (arr[2]-cur[2])/fabs(arr[2]-cur[2]); //додаємо або віднімаємо одиницю
                                                    //fabs потрібен для збереження знаку різниці
    Serial.print(" B: ");
    Serial.print(cur[2]);
    Serial.println(); //красивий вивід в монітор порта
    setRGB(cur); //викликаємо функцію зміни кольору світлодіоду
    delay(5);
  }
}

//в loop викликаємо функцію changer послідовно для кожного кольору в порядку, вказаному у завданні
void loop()
{
  changer(blue);
  Serial.println("----------------------------------------");
  delay(2000);
  changer(orange);
  Serial.println("----------------------------------------");
  delay(2000);  
  changer(viola);
  Serial.println("----------------------------------------");
  delay(2000);  
  changer(green);
  Serial.println("----------------------------------------");
  delay(2000);  
  changer(yellow);
  Serial.println("----------------------------------------");
  delay(2000);  
  changer(red);
  Serial.println("----------------------------------------");
  delay(2000);  
  changer(sky);
  Serial.println("----------------------------------------");
  delay(2000);  
  
}


// функція зміни кольору RGB-світлодіоду
void setRGB (int *arr)
{
analogWrite (RED, arr[0]);
analogWrite (GREEN, arr[1]);
analogWrite (BLUE, arr[2]);
delay (5);
}
