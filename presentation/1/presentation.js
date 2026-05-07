const slides = Array.from(document.querySelectorAll('.slide'));
const prevButton = document.getElementById('prev');
const nextButton = document.getElementById('next');
const fullscreenButton = document.getElementById('fullscreen');
const progressBar = document.getElementById('progress-bar');
const currentEl = document.getElementById('current');
const totalEl = document.getElementById('total');
const dotsEl = document.getElementById('dots');

let currentIndex = 0;

const dots = slides.map((slide, index) => {
  const dot = document.createElement('button');
  dot.className = 'dot';
  dot.type = 'button';
  dot.setAttribute('aria-label', `Ir para slide ${index + 1}: ${slide.dataset.title || ''}`);
  dot.addEventListener('click', () => goTo(index));
  dotsEl.appendChild(dot);
  return dot;
});

totalEl.textContent = slides.length;

const update = () => {
  slides.forEach((slide, i) => slide.classList.toggle('active', i === currentIndex));
  dots.forEach((dot, i) => dot.classList.toggle('active', i === currentIndex));
  currentEl.textContent = currentIndex + 1;
  const pct = slides.length > 1 ? (currentIndex / (slides.length - 1)) * 100 : 100;
  progressBar.style.width = `${pct}%`;
};

const goTo = (index) => {
  currentIndex = (index + slides.length) % slides.length;
  update();
};
const next = () => goTo(currentIndex + 1);
const prev = () => goTo(currentIndex - 1);

prevButton.addEventListener('click', prev);
nextButton.addEventListener('click', next);

fullscreenButton.addEventListener('click', () => {
  if (!document.fullscreenElement) {
    document.documentElement.requestFullscreen?.();
  } else {
    document.exitFullscreen?.();
  }
});

window.addEventListener('keydown', (event) => {
  if (event.target.tagName === 'INPUT' || event.target.tagName === 'TEXTAREA') return;
  switch (event.key) {
    case 'ArrowRight':
    case 'PageDown':
    case ' ':
      event.preventDefault();
      next();
      break;
    case 'ArrowLeft':
    case 'PageUp':
      event.preventDefault();
      prev();
      break;
    case 'Home':
      event.preventDefault();
      goTo(0);
      break;
    case 'End':
      event.preventDefault();
      goTo(slides.length - 1);
      break;
    case 'f':
    case 'F':
      fullscreenButton.click();
      break;
  }
});

let touchStartX = null;
window.addEventListener('touchstart', (e) => {
  touchStartX = e.changedTouches[0].clientX;
}, { passive: true });
window.addEventListener('touchend', (e) => {
  if (touchStartX === null) return;
  const dx = e.changedTouches[0].clientX - touchStartX;
  if (Math.abs(dx) > 50) (dx < 0 ? next : prev)();
  touchStartX = null;
}, { passive: true });

update();
