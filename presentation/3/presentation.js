const slides = Array.from(document.querySelectorAll('.slide'));
const screen = document.getElementById('screen');
const prevBtn = document.getElementById('prev');
const nextBtn = document.getElementById('next');
const fsBtn = document.getElementById('fullscreen');
const themeBtn = document.getElementById('theme-btn');
const cmdSlide = document.getElementById('cmd-slide');
const cmdTotal = document.getElementById('cmd-total');
const statusFile = document.getElementById('status-file');
const statusPos = document.getElementById('status-pos');
const statusProgress = document.getElementById('status-progress');
const resolutionEl = document.getElementById('resolution');

const themes = ['theme-green', 'theme-amber', 'theme-blue'];
let themeIndex = 0;

let currentIndex = 0;
const pad = (n) => String(n).padStart(2, '0');
cmdTotal.textContent = pad(slides.length);

const updateResolution = () => {
  const cols = Math.floor(window.innerWidth / 10);
  const rows = Math.floor(window.innerHeight / 18);
  resolutionEl.textContent = `${cols}×${rows}`;
};

const update = () => {
  slides.forEach((s, i) => s.classList.toggle('active', i === currentIndex));
  cmdSlide.textContent = pad(currentIndex + 1);
  const title = slides[currentIndex].dataset.title || '';
  statusFile.textContent = `"${title}"`;
  statusPos.textContent = `${pad(currentIndex + 1)},1`;
  const pct = Math.round(((currentIndex + 1) / slides.length) * 100);
  statusProgress.textContent = pct === 100 ? 'Bot' : (currentIndex === 0 ? 'Top' : `${pct}%`);
  screen.scrollTop = 0;
};

const goTo = (i) => { currentIndex = (i + slides.length) % slides.length; update(); };
const next = () => goTo(currentIndex + 1);
const prev = () => goTo(currentIndex - 1);

prevBtn.addEventListener('click', prev);
nextBtn.addEventListener('click', next);

fsBtn.addEventListener('click', () => {
  if (!document.fullscreenElement) document.documentElement.requestFullscreen?.();
  else document.exitFullscreen?.();
});

const cycleTheme = () => {
  document.body.classList.remove(themes[themeIndex]);
  themeIndex = (themeIndex + 1) % themes.length;
  document.body.classList.add(themes[themeIndex]);
};
themeBtn.addEventListener('click', cycleTheme);

window.addEventListener('keydown', (e) => {
  if (e.target.tagName === 'INPUT' || e.target.tagName === 'TEXTAREA') return;
  switch (e.key) {
    case 'ArrowRight':
    case 'PageDown':
    case ' ':
    case 'l':
    case 'j':
      e.preventDefault(); next(); break;
    case 'ArrowLeft':
    case 'PageUp':
    case 'h':
    case 'k':
      e.preventDefault(); prev(); break;
    case 'Home':
    case 'g':
      e.preventDefault(); goTo(0); break;
    case 'End':
    case 'G':
      e.preventDefault(); goTo(slides.length - 1); break;
    case 'f':
    case 'F':
      fsBtn.click(); break;
    case 't':
    case 'T':
      cycleTheme(); break;
  }
});

let touchX = null;
window.addEventListener('touchstart', (e) => { touchX = e.changedTouches[0].clientX; }, { passive: true });
window.addEventListener('touchend', (e) => {
  if (touchX === null) return;
  const dx = e.changedTouches[0].clientX - touchX;
  if (Math.abs(dx) > 60) (dx < 0 ? next : prev)();
  touchX = null;
}, { passive: true });

window.addEventListener('resize', updateResolution);
updateResolution();
update();
