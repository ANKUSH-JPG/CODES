function first()
{
	var a=document.getElementById("canvas");
	canvas=a.getContext('2d');
	
	canvas.fillStyle="red";
	canvas.strokeRect(10,40,100,500);
	canvas.strokeRect(10,10,900,20);
	canvas.strokeRect(130,40,800,500);
	
	canvas.font="15px solid tahoma";
	canvas.textAlign="start";
	canvas.fillText("TODO APP",500,25);
	
	canvas.font="10px solid tahoma";
	canvas.textAlign="start";
	canvas.fillText("ACTIVE",50,50);
}

window.addEventListener("load",first,false);