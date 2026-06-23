<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Automated Grow Bench Dashboard</title>
<script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
<style>
*{margin:0;padding:0;box-sizing:border-box;font-family:'Segoe UI',sans-serif;}
body{
background:linear-gradient(135deg,#071426,#0b1f36);
color:white;
min-height:100vh;
padding:25px;
}
.container{max-width:1600px;margin:auto;}
h1{
text-align:center;
color:#4da6ff;
margin-bottom:30px;
font-size:2.3rem;
}
.status-bar{
display:flex;
justify-content:center;
gap:20px;
margin-bottom:25px;
flex-wrap:wrap;
}
.status{
padding:12px 24px;
border-radius:30px;
background:#0d1b2a;
border:1px solid #1f3a5f;
backdrop-filter:blur(10px);
}
.cards{
display:grid;
grid-template-columns:repeat(3,1fr);
gap:20px;
margin-bottom:25px;
}
.card{
background:#0d1b2a;
border:1px solid #1f3a5f;
border-radius:18px;
padding:25px;
text-align:center;
box-shadow:0 0 20px rgba(77,166,255,.15);
backdrop-filter:blur(10px);
transition:.3s;
}
.card:hover{
transform:translateY(-5px);
background:#132238;
}
.card h2{
color:#4da6ff;
margin-bottom:10px;
}
.value{
font-size:2.6rem;
font-weight:bold;
}
.graphs{
display:grid;
grid-template-columns:repeat(3,1fr);
gap:20px;
}
.graph-card{
background:#0d1b2a;
border:1px solid #1f3a5f;
border-radius:18px;
padding:15px;
height:380px;
backdrop-filter:blur(10px);
}
.footer{
text-align:center;
margin-top:25px;
color:#b8c7d9;
}
canvas{
width:100%!important;
height:100%!important;
}
@media(max-width:1100px){
.cards,.graphs{grid-template-columns:1fr;}
}
</style>
</head>
<body>

<div class="container">
<h1>🌱 Automated Grow Bench Dashboard</h1>

<div class="status-bar">
<div class="status">Mode : <span id="mode">--</span></div>
<div class="status">Pump : <span id="pump">--</span></div>
</div>

<div class="cards">
<div class="card">
<h2>Temperature</h2>
<div class="value" id="temp">-- °C</div>
</div>

<div class="card">
<h2>Humidity</h2>
<div class="value" id="hum">-- %</div>
</div>

<div class="card">
<h2>Soil Raw Value</h2>
<div class="value" id="soil">--</div>
</div>
</div>

<div class="graphs">
<div class="graph-card"><canvas id="tempChart"></canvas></div>
<div class="graph-card"><canvas id="humChart"></canvas></div>
<div class="graph-card"><canvas id="soilChart"></canvas></div>
</div>

<div class="footer">
Last Updated : <span id="updated">--</span>
</div>
</div>

<script>
const API_KEY = "My_API_Key";
const BASE_URL = "https://careers.zelbytes.com/api/iot-lab/v1";

function createChart(canvasId,label){
return new Chart(document.getElementById(canvasId),{
type:'line',
data:{
labels:[],
datasets:[{
label:label,
data:[],
borderColor:'#4da6ff',
backgroundColor:'rgba(77,166,255,0.15)',
fill:true,
tension:0.35,
borderWidth:3
}]
},
options:{
responsive:true,
maintainAspectRatio:false,
plugins:{legend:{labels:{color:'white'}}},
scales:{
x:{ticks:{color:'white'},grid:{color:'rgba(255,255,255,0.1)'}},
y:{ticks:{color:'white'},grid:{color:'rgba(255,255,255,0.1)'}}
}
}
});
}

const tempChart=createChart("tempChart","Temperature °C");
const humChart=createChart("humChart","Humidity %");
const soilChart=createChart("soilChart","Soil Moisture %");

async function fetchLatest(){
try{
const response=await fetch(`${BASE_URL}/telemetry/latest`,{
headers:{"X-Iot-Lab-Key":API_KEY}
});
const data=await response.json();
const latest=data.latest||{};

document.getElementById("temp").innerHTML=`${latest.temperature_c ?? "--"} °C`;
document.getElementById("hum").innerHTML=`${latest.humidity_pct ?? "--"} %`;
document.getElementById("soil").innerHTML=`${latest.soil_moisture_pct ?? "--"}`;
document.getElementById("mode").innerHTML=latest.mode ?? "AUTO";
document.getElementById("pump").innerHTML=(latest.pump_state==1)?"ON":"OFF";
document.getElementById("updated").innerHTML=new Date().toLocaleTimeString();
}catch(err){console.error(err);}
}

async function updateSeries(){
const fields=["temperature_c","humidity_pct","soil_moisture_pct"];
const charts=[tempChart,humChart,soilChart];

for(let i=0;i<fields.length;i++){
try{
const response=await fetch(
`${BASE_URL}/telemetry/series?field=${fields[i]}&limit=20`,
{headers:{"X-Iot-Lab-Key":API_KEY}}
);
const data=await response.json();
charts[i].data.labels=data.labels||[];
charts[i].data.datasets[0].data=data.values||[];
charts[i].update();
}catch(err){console.error(err);}
}
}

async function refreshDashboard(){
await fetchLatest();
await updateSeries();
}

refreshDashboard();
setInterval(refreshDashboard,5000);
</script>

</body>
</html>
