function comprobar()
{
var pregunta1= document.copia.preg1.value;
var pregunta2= document.copia.preg2.value;
var pregunta3= document.copia.preg3.value;
var pregunta4= document.copia.preg4.value;
var pregunta5= document.copia.preg5.value;
var pregunta6= document.copia.preg6.value;
var contador= 0;

	if(pregunta1=="MQ3")
	{
		contador= contador + 1;
	}
	if(pregunta2=="MQ135")
	{
		contador= contador + 1;
	}
	if(pregunta3=="BMP180")
	{
		contador= contador + 1;
	}

	if(pregunta4=="MQ9")
	{
		contador= contador + 1;
	}

	if(pregunta5=="MQ7")
	{
		contador= contador + 1;
	}

	if(pregunta6=="MQ8")
	{
		contador= contador + 1;
	}
switch(contador)
{
	case 0:
	$.Zebra_Dialog('<strong>Regular</strong>, no acertaste ninguna pregunta correctamente', {
    'type':     'error',
    'title':    'Quiz resultado'
});
	break;
case 1:
	$.Zebra_Dialog('<strong>Muy mal</strong>, respondiste 1 pregunta correctamente', {
    'type':     'confirmation',
    'title':    'Quiz resultado'
});
	break;
case 2:
	$.Zebra_Dialog('<strong>Mal</strong>, respondiste 2 preguntas correctamente', {
    'type':     'confirmation',
    'title':    'Quiz resultado'
});
	break;
case 3:
	$.Zebra_Dialog('<strong>Casi bien</strong>, respondiste 3 preguntas correctamente', {
    'type':     'confirmation',
    'title':    'Quiz resultado'
});
    break;
case 4:
	$.Zebra_Dialog('<strong>Bien</strong>, respondiste 4 preguntas correctamente', {
    'type':     'confirmation',
    'title':    'Quiz resultado'
});
    break;
case 5:
	$.Zebra_Dialog('<strong>Muy bien</strong>, respondiste 5 preguntas correctamente', {
    'type':     'confirmation',
    'title':    'Quiz resultado'
});
    break;
case 6:
	$.Zebra_Dialog('<strong>Excelente</strong>, respondiste 6 preguntas correctamente', {
    'type':     'confirmation',
    'title':    'Quiz resultado'
});
	break;       

}


}


var p1a=new Vue({
	el: '#p1a',
	data:{ 
	  p1: 'No se'
	}
  })


  var p2a=new Vue({
	el: '#p2a',
	data:{ 
	  p2: 'No se'
	}
  })


  var p3a=new Vue({
	el: '#p3a',
	data:{ 
	  p3: 'No se'
	}
  })


  var p4a=new Vue({
	el: '#p4a',
	data:{ 
	  p4: 'No se'
	}
  })


  var p5a=new Vue({
	el: '#p5a',
	data:{ 
	  p5: 'No se'
	}
  })


  var p6a=new Vue({
	el: '#p6a',
	data:{ 
	  p6: 'No se'
	}
  })