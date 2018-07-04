Paycell iOS SDK
===============
[![CocoaPods](https://img.shields.io/cocoapods/v/PaycellSDK.svg?maxAge=3600&style=flat-square)]()  [![CocoaPods](https://img.shields.io/cocoapods/l/PaycellSDK.svg?maxAge=2592000&style=flat-square)]()  [![CocoaPods](https://img.shields.io/cocoapods/p/PaycellSDK.svg?maxAge=2592000&style=flat-square)]()

Kullanici isyeri uygulamasinda odeme gerceklestirilecek adimda “Paycell ile odeme yapmak istiyorum.” secildiginde [Paycell](https://www.paycell.com.tr) ekranlarina yonlendirilerek telefon numarasina kayitli odeme methodlari uzerinden veya yeni odeme methodu ekleyerek odeme yapmasini saglayan SDK’dir. SDK'nin amaci odeme islemini [Paycell](https://www.paycell.com.tr) araciligi ile bitirip kullanici isyeri uygulamasina islem sonucu hakkinda geri donus saglamaktir.

## Installation
Kredi karti taramasinda kullanilmak uzere alinacak kamera izni metni uygulamanin plist dosyasina eklenir (**NSCameraUsageDescription**). 

```xml    
<key>NSCameraUsageDescription</key>
<string>Kullaniciya gosterilecek aciklama metni</string>
```

**App Transport Security** ayarlari yapilir.  
    
```xml    
  <key>NSAppTransportSecurity</key>
  <dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
    <key>NSAllowsArbitraryLoadsInWebContent</key>
    <true/>
    <key>NSExceptionDomains</key>
    <dict>
      <key>services.paycell.com.tr</key>
      <dict>
        <key>NSExceptionAllowsInsecureHTTPLoads</key>
        <true/>
        <key>NSIncludesSubDomains</key>
        <true/>
      </dict>
      <key>omccstb.turkcell.com.tr</key>
      <dict>
        <key>NSExceptionAllowsInsecureHTTPLoads</key>
        <true/>
        <key>NSIncludesSubDomains</key>
        <true/>
      </dict>
    </dict>
  </dict>
```

Daha sonra asagidaki iki yontemden biri secilerek entegrasyon tamamlanir.


##### Cocoapods ile entegrasyon;
Podfile'a eklenerek entegrasyon yapilabilir.

```
  pod 'PaycellSDK'
```

##### Elle entegrasyon;
Paycell SDK'yi projeye eklemek icin PaycellSDK.framework proje icine eklenir.


## Odeme Akisi

##### Uygulama;

 * odeme istegi olusturma
 * SDK’yi initleyerek odeme istegini SDK’ya iletme
 * odeme durumunu bekleme

##### PaycellSDK;

 * odeme akisinda UI elemanlari gosterip, odeme bilgilerini ve ardindan kullanicidan odeme alma
 * odeme sonucunu uygulamaya iletme



## Ornek Kod

* **PaycellPaymentConfigurator ayarlanmalidir.**


```
| ---------------------------------------------------------------------------------------- |
| Parametre adi | Aciklama                                                                 |
| ------------- | ------------------------------------------------------------------------ |
| merchantCode  | Uye isyeri icin paylasilacaktir.                                         |
| terminalCode  | Uye isyeri icin paylasilacaktir.                                         |
| secureCode    | Uye isyeri icin paylasilacaktir.                                         |
| language      | SDK’nin dil degeridir.                                                   |
| hostAccount   | Uye isyeri uygulamasinda odemeyi yapan kullaniciyi ifade eden degerdir.  |
| merchantLogo  | SDK’da kullanilacak logodur.                                             |
| environment   | Demo, Test ve Live ortam parametresi                                     |
| ---------------------------------------------------------------------------------------- |
```



```
    [[PaycellPaymentConfigurator sharedConfigurator] setMerchantCode:@”1234”
                                                     andTerminalCode:@”12345”
                                                       andSecureCode:@”12345”
                                                         andLanguage:@”tr”
                                                      andHostAccount:@”example@example.com”
                                                     andMerchantLogo:[UIImage imageNamed:@"merchantLogo"]
                                                      andEnvironment:PaycellEnvironmentTest];
```

```
 Not: Uye isyeri uygulamasinda kullanici dogrulamasi mail adresi ile yapiliyorsa -hostAccount- alaninda mail adresi gonderilebilir.
```

* **Odeme olusturulmadan once Taksit veya DCB’ye ozel farkli odeme tutari var ise bunlar PaycellInstallment olarak olusturulmalidir.**


```
| ----------------------------------------------------------------------------- |
| Parametre adi         | Aciklama                                              |
| --------------------- | ----------------------------------------------------- |
| totalAmount           | Taksit objesinin toplam tutari                        |
| installmentCount      | Taksit objesinin kac taksit olacagi bilgisi           |
| installmentCardBrand  | Taksit objesinin hangi kart tipi icin gecerli oldugu  |
| installmentLineId     | Her bir taksit objesi icin tekil kullanilacak deger   |
| installmentMethodType | Taksit objesinin DCB veya CREDIT_CARD oldugu bilgisi  |
| ----------------------------------------------------------------------------- |
```



```
    PaycellInstallment* installment = [[PaycellInstallment alloc] initWithTotalAmount:@"90"
                                                                     installmentCount:2
                                                                 installmentCardBrand:PaycellInstallmentBrand_AXESS
                                                                    installmentLineId:@"1"
                                                                installmentMethodType:@"CREDIT_CARD"];
```



* **PaycellPayment Objesi olusturulmalidir.**


```
| ----------------------------------------------------------------------- |
| Parametre adi         | Aciklama                                        |
| --------------------- | ----------------------------------------------- |
| amount                | Odemenin toplam tutari                          |
| currency              | Odemenin para birimi (TL icin 99 gonderilmeli)  |
| securityOption        | Odemenin 3d veya 2d oldugu bilgisi              |
| referenceNumber       | Odemenin referans numarasi                      |
| installmentPlans      | Odemenin destekledi taksitler listesi           |
| ----------------------------------------------------------------------- |
```



```
    PaycellPayment* payment = [[PaycellPayment alloc] initWithAmount:AMOUNT
                                                            currency:@”99”
                                                      securityOption:@”NON_THREED_SECURE”
                                                     referenceNumber:REFERENCE_NUMBER
                                                    installmentPlans:@[installment1, installment2, installment3]];
```



* **Uygulama icinde odemenin alinacagi sayfada “PaycellPaymentDelegate” delege olarak eklenmelidir.**


* **PaycellPaymentViewController initlenerek ekranda present edilir.**



```
    PaycellPaymentViewController* paycellVC = [[PaycellPaymentViewController alloc] initWithPayment:payment 
                                                                                           delegate:self];

    [self presentViewController:paycellVC
                       animated:Yes
                     completion:nil];
```



* **PaycellPaymentDelegate delegelerinde cevap beklenir ve *dismissViewControllerAnimated:completion:* ile PaycellPaymentViewController’in kapatilmasi saglanir.**



## Paycell Error Code

 * PaycellErrorCodeUserCancelled -> Kullanici SDK dan islemi tamamlamadan cikarsa donecek hata kodu
 * PaycellErrorCodeException -> SDK icinde exception alinmasi durumunda donecek hata kodu
 * PaycellTimeoutCodeException -> Uygulamada timeout suresi doldugunda donecek hata kodu
 * PaycellTimeoutAfterPaymentCodeException -> Odeme isleminden sonra timeout suresi doldugunda donecek hata kodu


## Ek bilgiler

 * Turkce icin dil parametresi “tr” yollanmalidir.
 * MerchantCode, TerminalCode ve SecureCode her uye isyeri icin paylasilacaktir.
 * InstallmentMethodType olarak “CREDIT_CARD” veya “DCB” iletilir.
 * LineId icin her satir icin tekil olacak sekilde kullanilmalidir.
 * Ilgili taksit adedi icin satis tutari farkli odeme araclari icin farkli fiyat kullanilmak istenirse ilgili odeme araci icin installmentPlan degiskenine count=1 olarak bilgi eklenir.
 * Amount alanlarinda tutarin son iki hanesi kurus ifade eder. 
 * 15.55 lira icin 1555 iletilir
 * 13.00 lira icin 1300 iletilir
 * SecurityOption olarak “THREED_SECURE” veya “NON_THREED_SECURE” iletilir.
 * Currency olarak TL icin “99” gonderilir.


