async function fetchData() {
  try {
    const response = await fetch('/data');
    return await response.json();
  } catch (error) {
    console.error('Error fetching data:', error);
    return null;
  }
}

function updateUI(data) {
  if (!data) return;

  const setStatus = (id, value, isOn) => {
    const el = document.getElementById(id);
    el.innerText = value;
    el.className = isOn ? 'status-on' : 'status-off';
  };

  setStatus('temp', `${data.temperature.toFixed(1)} °C`, true);
  setStatus('hum', `${data.humidity.toFixed(1)} %`, true);
  setStatus('bulb', data.bulb ? 'ON' : 'OFF', data.bulb);
  setStatus('vent', data.ventOpen ? 'Open' : 'Closed', data.ventOpen);
}

async function update() {
  const data = await fetchData();
  updateUI(data);
}

window.onload = () => {
  update();
  setInterval(update, 5000);
};
