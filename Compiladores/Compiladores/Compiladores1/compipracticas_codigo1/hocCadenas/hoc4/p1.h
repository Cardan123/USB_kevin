
struct punto { x
  y
}
punto.x

punto.x = 4
punto.y = 3
punto.x * punto.x + punto.y * punto.y

struct punto { x
y
}

struct punto p1

p1.x = 4
p1.y = 3
p1.x * p1.x + p1.y * p1.y

struct punto p2

p2.x = 40
p2.y = 30
p2.x * p2.x + p2.y * p2.y

struct punto p3
p3.x = p1.x + p2.x
p3.x

struct punto { x
y
}

struct punto p1
struct punto p2
struct punto p3

proc p(){
 p1.x = 4
 p1.y = 3
 p1.x * p1.x + p1.y * p1.y
 p2.x = 40
 p2.y = 30
 p2.x * p2.x + p2.y * p2.y
 p3.x = p1.x + p2.x
 print p3.x
}
p()


proc prueba(){
	i=0
	while(i<10){
		print i
		i=i+1
	}
}

prueba()

proc prueba(){
	i=0
	for(i=0 ; i < 5 ; i = i + 1){
           for(j=0; j < 7 ; j = j + 1){
		print i , j
           }
	}
}

prueba()

dim a[3][3]
proc prueba(){	
	for(i=0 ; i < 3 ; i = i + 1){
           for(j=0 ; j < 3 ; j = j + 1){
		a[i][j] = (i+1) + (j+1)
           }
	}
        for(i=0 ; i < 3 ; i = i + 1){
           for(j=0 ; j < 3 ; j = j + 1){
		print i , j , a[i][j]
           }
	}
}

prueba()







dim a[3][3]
proc prueba(){	
	for(i=0 ; i < 3 ; i = i + 1){
           for(j=0 ; j < 3 ; j = j + 1){
		a[i][j] = (i) + (j)
           }
	}
        for(i=0 ; i < 3 ; i = i + 1){
           for(j=0 ; j < 3 ; j = j + 1){
		print i , j , ( 10 * a[i][j] )
           }
	}
}

prueba()

x = 100+900
dim a[100][100]
proc prueba(){	
	for(_i=0 ; _i < $1 ; _i = _i + 1){
           for(_j=0 ; _j < $2 ; _j = _j + 1){
		a[_i][_j] = (_i) + (_j)
           }
	}
        for(_i=0 ; _i < $1 ; _i = _i + 1){
           for(_j=0 ; _j < $2 ; _j = _j + 1){
		print _i , _j , ( 1000 * a[_i][_j] )
           }
	}
}

prueba(10 , 10)

func mult(){
  _i = [0x0]
  _acu = [0x2]
  while(_i< $2){	
                _acu = _acu + $1
		_i=_i+[1x0]
	}
   return _acu
}
x= mult([2x2], [5x2])

dim a[100]
func mult(){
  _i = 0
  _acu = 0
  while(_i< $2){	
                _acu = _acu + $1
		_i=_i+1
	}
   return _acu
}
func power(){
   _i = 0
  _acu = 1
  while(_i< $2){	
                _acu = mult(_acu, $1)
		_i=_i+1
	}
   return _acu
}
func sumato(){
  _i = 0
  _acu = 0
  while(_i< $2){	
                a[_i]=power($1, _i)
                _acu = _acu + power($1, _i)
                print _acu
		_i=_i+1
   }
   return _acu
}
x = sumato(2, 12)
print a[10]

func p( u, w , x, y , z ) { return u+w+x+y+z }
x=p(1,2,3,4,5)
y=p(10,20,30,40,50)
z=p(100,200,300,400,500)
a=p(1000,2000,3000,4000,5000)



dim aa[100]
func mult(a, b){
  _i = 0
  _acu = 0
  while(_i< b){	
                _acu = _acu + a
		_i=_i+1
	}
   return _acu
}
func potencia(a, b){
   _i = 0
  _acu = 1
  while(_i< b){	
                _acu = mult(_acu, a)
		_i=_i+1
	}
   return _acu
}
func sumato( a , b ){
  _i = 0
  _acu = 0
  while( _i < b ){	
                aa[_i] = potencia(a, _i)
                _acu = _acu + potencia(a , _i)
                print _acu
		_i=_i+1
   }
   return _acu
}
x = sumato( 2, 12)
print aa[10]

dim a[100][100]
proc prueba(filas , cols){	
	for(_i=0 ; _i < filas ; _i = _i + 1){
           for(_j=0 ; _j < cols ; _j = _j + 1){
		a[_i][_j] = (_i) + (_j)
           }
	}
        for(_i=0 ; _i < filas ; _i = _i + 1){
           for(_j=0 ; _j < cols ; _j = _j + 1){
		print _i , _j , ( 1000 * a[_i][_j] )
           }
	}
}
prueba(10 , 10)



