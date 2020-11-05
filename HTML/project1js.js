var current_player=1;

window.onload=init;



function init()
{
	document.getElementById('winner').style.display='none';
	document.getElementById('local_value1').textContent=0;
	document.getElementById('local_value2').textContent=0;
	document.getElementById('current_value1').textContent=0;
	document.getElementById('current_value2').textContent=0;
	
	document.getElementById('roll_dice').addEventListener('click',firstFunction);
	document.getElementById('hold').addEventListener('click' , holdFunction);
	document.getElementById('game_button').addEventListener('click' , newGame);
	
}

function firstFunction()
{
var dice_value=Math.floor(Math.random()*6)+1;
document.getElementById('dice').textContent=dice_value;

if(current_player === 1)
{
	document.getElementById('local_value'+current_player).textContent=dice_value;
	var current_value=Number(document.getElementById('current_value'+current_player).textContent);
	if(dice_value === 1)
	{
		document.getElementById('current_value'+current_player).textContent=0;
		current_player=2;
	}
	else
	{
        current_value +=dice_value;
		document.getElementById('current_value'+current_player).textContent=current_value;
		
		if(current_value >= 50)
		{
			console.log('WINNER 1');
			document.getElementById('dice').style.display='none';
			document.getElementById('dice_value').style.display='none';
			document.getElementById('roll_dice').style.display='none';
			document.getElementById('hold').style.display='none';
			document.getElementById('winner').style.display='block';
			document.getElementById('winner').textContent='PLAYER 1 WINS !!!!!!!!';
		}
	}
}
else if(current_player === 2)
{
	document.getElementById('local_value'+current_player).textContent=dice_value;
	var current_value=Number(document.getElementById('current_value'+current_player).textContent);
	
	if(dice_value === 1)
	{
		document.getElementById('current_value'+current_player).textContent=0;
		current_player=1;
	}
	else
	{
		current_value += dice_value;
		document.getElementById('current_value'+current_player).textContent=current_value;
		if(current_value >= 50)
		{
			console.log('WINNER 2');
			document.getElementById('dice').style.display='none';
			document.getElementById('dice_value').style.display='none';
			document.getElementById('roll_dice').style.display='none';
			document.getElementById('hold').style.display='none';
			document.getElementById('winner').style.display='block';
			document.getElementById('winner').textContent='PLAYER 2 WINS !!!!!!!!';
		}
	}
}


console.log(dice_value);
}

function holdFunction()
{
	if(current_player === 1)
	{
		console.log('HOLD1');
		current_player=2;
		
	}
	else if(current_player ===2)
	{
		console.log('HOLD2');
		current_player=1;
	}
}

function newGame()
{
	document.getElementById('winner').style.display='none';
	document.getElementById('local_value1').textContent=0;
	document.getElementById('local_value2').textContent=0;
	document.getElementById('current_value1').textContent=0;
	document.getElementById('current_value2').textContent=0;
	
	document.getElementById('dice').style.display='block';
	document.getElementById('dice_value').style.display='block';
	document.getElementById('roll_dice').style.display='block';
	document.getElementById('hold').style.display='block';
	
}
