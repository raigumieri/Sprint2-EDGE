//Definindo variáveis (Temperatura)

int sensorTemp = A0;

//Definindo variáveis (Umidade do ar)

int umidade; //Variável umidade

//Definição de variáveis (Umidade do solo)

const int sensorPin = A2; 
int umidadeSolo;


void setup()
{
  
  pinMode(A1, INPUT); //Sensor de umidade do Ar
  
  Serial.begin(9600); //Monitor serial habilitado
}

void loop()
{
  
//Sensor de temperatura
  
  int valorSensor = analogRead(sensorTemp);
  
  float tensao = valorSensor*5;
  tensao = (tensao/1023);
  float temperaturaC = (tensao-0.5)*100;
  
  Serial.print("Temperatura: ");
  Serial.println(temperaturaC);
   
    
  delay(2000); //2 segundos
  
//Sensor de umidade do ar usando o potenciômetro
  
  umidade = analogRead(A1);
  int umidade_P(map(umidade, 0, 1023, 0, 100));
  
  
  Serial.print("Umidade do ar: ");
  Serial.print(umidade_P);
  Serial.println("%");
  
  
  delay(1000);
  
//Sensor de umidade do solo
  
  umidadeSolo = analogRead(sensorPin); // Leitura do sensor de umidade do solo
  umidadeSolo = map(umidadeSolo, 0, 1023, 0, 100); // Mapeia o valor lido para um valor em percentual(0-100)
  
  Serial.print("Umidade do Solo: "); 
  Serial.print(umidadeSolo);
  
  Serial.println("%");
  delay(1000);
 
}