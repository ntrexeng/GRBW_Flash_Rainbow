#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// 네오픽셀을 사용하기 위한 함수 선언
// 첫번째 인자 : 네오픽셀 LED 개수
// 두번째 인자 : 네오픽셀이 연결된 아두이노의 PIN 번호
// 세번째 인자 : 네오픽셀의 타입 (RGB, RGBW 등)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {

// 네오픽셀 초기화 ( 모든 LED OFF )
  strip.begin();
  strip.show(); 
  
}

void loop() {

// 아래의 순서대로 네오픽셀 반복

// strip.Color(a, b, c), d) = strip.Color(Red, Green, Blue, White), Brightness)
// Red(빨강), Green(초록), Blue(파랑), White(하양), Brightness(밝기) 의 색상을 각 255단계로 제어

  theaterChase(strip.Color(0, 0, 0, 255), 50); // 하얀색
  theaterChase(strip.Color(255, 0, 0, 0), 50); // 빨간색
  theaterChase(strip.Color(255, 50, 0, 0), 50); // 주황색
  theaterChase(strip.Color(255, 100, 0, 0), 50); // 노랑색
  theaterChase(strip.Color(0, 255, 0, 0), 50); // 초록색
  theaterChase(strip.Color(0, 165, 235, 0), 50); // 파란색
  theaterChase(strip.Color(0, 0, 255, 0), 50); // 남색
  theaterChase(strip.Color(105, 0, 105, 0), 50); // 보라색
}

// 입력한 색으로 LED를 깜빡여주는 함수
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// 255가지의 색을 표현하는 함수
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
