var search=prompt("SEARCH");

console.log("you searched for "+search);

/*
var markh=78;
var markw=1.69;
var johnh=92;
var johnw=1.95;

var markBmi=markw/(markh*markh);
var johnBmi=johnw/(johnh*johnh);

var output= markBmi > johnBmi;
console.log("MARKS BMI HIGHER THAN JHONS ?",output);

var bills=[124,48,268];

var billsLength=bills.length;
var tips=new Array();
var finalAmount=new Array();

var i=0;
while(i<billsLength)
{
	if(bills[i]<50)
	{
		tips[i]=bills[i]*0.2;
		finalAmount[i]=bills[i]+tips[i];
	}
	else if(bills[i]>=50 && bills[i]<=200)
	{
		tips[i]=bills[i]*0.15;
		finalAmount[i]=bills[i]+tips[i];
	}
	else if(bills[i]>=200)
	{
		tips[i]=bills[i]*0.1;
		finalAmount[i]=bills[i]+tips[i];
	}
	i++;
}

console.log(tips);
console.log(finalAmount);*/

/*
function calculate()
{
	var BMI=this.mass/(this.height*this.height);
}

var detailsJ= {
	name:'john',
	mass:92,
	height:1.95, 
	output: calculate()
}
var detailsM= {
	name:"Mark",
	mass:78,
	height:1.69,
	output: calculate()
}
var result= detailsM.output > detailsJ.output;
console.log("MARKS BMI HIGHER THAN JHONS",result);*/

/*
let [result1,result2]=calculateAge(2000);

function calculateAge(age){
	
	let my_age=age;
	return[my_age,2020-age];
	
}
console.log(result1);
console.log(result2);*/

class parks{
	constructor(name,no_of_trees,YOE,area)
	{
		this.name=name;
		this.no_of_trees=no_of_trees;
		this.YOE=YOE;
		this.area=area;
		
		this.age=2020-this.YOE;
	}
		calculate_density(){
			var density=(this.no_of_trees/this.area);
			
		console.log(`${this.name} has a tree density of ${density}`);
			
		}
	
}

const park1=new parks('Green park',215,1987,0.2);
const park2=new parks('National Park',3541,1894,2.9);
const park3=new parks('Oak Park',949,1953,0.4);

console.log("------------------ PARKS RESULT ----------------------");
park1.calculate_density();
park2.calculate_density();
park3.calculate_density();


const park_details=new Map();

park_details.set(1,park1);
park_details.set(2,park2);
park_details.set(3,park3);

var total_age=0;
park_details.forEach((value,key) => total_age += value.age);

var avg_age=total_age/3;
console.log(avg_age);



















































































