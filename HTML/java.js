function first{
	barSize=700;
	getVideo=document.getElementById('addingVideo');
	getButton=document.getElementById('addingButton');
	getFrame=document.getElementById('progressFrame');
	getBar=document.getElementById('progressBar');
	
	getButton.addEventListener('click',playorpause,false);
	getFrame.addEventListener('click',clickedbar,false);
	
}

function playorpause()
{
	if(!getVideo.paused && !getVideo.ended){
		getVideo.pause();
		getButton.innerHTML='PLAY';
		window.clearInterval(updateBar);
	}
	else{
		getVideo.play();
		getButton.innerHTML='PAUSE';
		updateBar=setInterval(update,500); 
		
	}
	 
}

function update()
{
	if(!getVideo.ended)
	{
		var size=parseInt(getVideo.currentTime*barSize/getVideo.duration);
		getBar.style.width=size+'px';
	}
	else
	{
		getBar.style.width='0px';
		getButton.innerHTML='PLAY';
		window.clearInterval(updateBar);
		
	}
	
}