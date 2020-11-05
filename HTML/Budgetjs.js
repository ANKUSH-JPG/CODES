window.onload=init;

function init()
{
	document.getElementById('add').addEventListener('click',clicked_Add);
}

function clicked_Add(){
	var get_result=(function(){
	var get_increase_decrease=document.getElementById('increase_decrease').value;
	var get_desc=document.getElementById('desc').value;
	var get_value=document.getElementById('get_value').value;

	(function(){
		var html;
		
		
		if(get_increase_decrease === 'inc')
		{
			console.log('Income'+' '+get_desc+' '+get_value);
			html='HELLO';
			window.onload=function a(){
				onsole.log('Income');
			document.querySelector('income_UI').inserAdjacentHTML('beforeend',html);};
		}
		else if(get_increase_decrease === 'dec')
		{
			console.log('Expenses'+' '+get_desc+' '+get_value);
			
		}
		
		
	})();
		
	})();
	
	
}
