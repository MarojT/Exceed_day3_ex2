# Exceed_day3_ex2

Exercise 2 (Medium)

Board WEMOS : LOLIN D32 PRO

งานนี้มีจุดประสงค์ให้เรา นำ http request มาใช้ร่วมกับ multitasking โดยเป็นการรับค่าจาก server ด้วยการ GET และนำค่านั้นไปใช้งานควบคุมการทำงานของ hardware 

โดยสิ่งที่จะต้อง GET คือค่า Delay ที่เราจะเอาไปใช้ควบคุมความเร็วในการกระพริบของ Built-in LED 

API URL สำหรับ GET ค่า : https://exceed-hardware-stamp465.koyeb.app/leddelay

โดย API ดังกล่าวจะส่ง JSON message ในลักษณะ

{

      “value” : int
      
}

โดย ค่า value คือค่า Delay ระหว่างติดและดับ
ให้ทำการ GET ทุกๆ 5 วินาที (นั้นคือไฟจะกระพริบด้วยความถี่หนึ่งๆ เป็นเวลา 5 วินาที แล้วเปลี่ยนไป)
แสดง ค่า delay ที่ได้รับมาในทุกๆครั้งผ่าน serial Monitor
ไฟต้องกระพริบอยู่ตลอดเวลาที่ระบบทำงาน (หรือก็คือต้องใช้  Multitasking เท่านั้น)
