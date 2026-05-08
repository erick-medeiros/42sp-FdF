const slides = Array.from(document.querySelectorAll('.slide'));
const prevBtn = document.getElementById('prev');
const nextBtn = document.getElementById('next');
const fsBtn = document.getElementById('fullscreen');
const dwgNo = document.getElementById('dwg-no');
const dwgTitle = document.getElementById('dwg-title');
const tbSheet = document.getElementById('tb-sheet');
const tbCurr = document.getElementById('tb-curr');
const tbTotal = document.getElementById('tb-total');
const tbFile = document.getElementById('tb-file');
const tbBar = document.getElementById('tb-bar');
const sheetEl = document.getElementById('sheet');

const pad = (n) => String(n).padStart(2, '0');
const slug = (s) => s.toLowerCase().replace(/[^a-z0-9]+/g, '_').replace(/^_|_$/g, '');

let currentIndex = 0;
const total = slides.length;
tbTotal.textContent = pad(total);

const update = () => {
  slides.forEach((s, i) => s.classList.toggle('active', i === currentIndex));
  const slide = slides[currentIndex];
  const title = slide.dataset.title || '';
  const num = pad(currentIndex + 1);
  dwgNo.textContent = num;
  dwgTitle.textContent = title;
  tbSheet.textContent = `${num} / ${pad(total)}`;
  tbCurr.textContent = num;
  tbFile.textContent = `${slug(title) || 'sheet'}.dwg`;
  const pct = ((currentIndex + 1) / total) * 100;
  tbBar.style.width = pct + '%';
  sheetEl.scrollTop = 0;
};

const goTo = (i) => { currentIndex = (i + total) % total; update(); };
const next = () => goTo(currentIndex + 1);
const prev = () => goTo(currentIndex - 1);

prevBtn.addEventListener('click', prev);
nextBtn.addEventListener('click', next);

fsBtn.addEventListener('click', () => {
  if (!document.fullscreenElement) document.documentElement.requestFullscreen?.();
  else document.exitFullscreen?.();
});

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
      e.preventDefault(); goTo(total - 1); break;
    case 'f':
    case 'F':
      fsBtn.click(); break;
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

update();
