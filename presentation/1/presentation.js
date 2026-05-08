const slides = Array.from(document.querySelectorAll('.slide'));
const prevButton = document.getElementById('prev');
const nextButton = document.getElementById('next');
const fullscreenButton = document.getElementById('fullscreen');
const progressBar = document.getElementById('progress-bar');
const currentEl = document.getElementById('current');
const totalEl = document.getElementById('total');
const dotsEl = document.getElementById('dots');
const slidesEl = document.getElementById('slides');

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

const goTo = (index, dir = 'forward') => {
  currentIndex = (index + slides.length) % slides.length;
  slidesEl.dataset.dir = dir;
  update();
};
const next = () => goTo(currentIndex + 1, 'forward');
const prev = () => goTo(currentIndex - 1, 'back');

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

// Animated rotating wireframe for slide 1
function initWireframe() {
  const canvas = document.getElementById('wireframe-canvas');
  if (!canvas) return;

  const dpr = window.devicePixelRatio || 1;
  const displayW = canvas.width;
  const displayH = canvas.height;
  canvas.width = displayW * dpr;
  canvas.height = displayH * dpr;
  canvas.style.width = displayW + 'px';
  canvas.style.height = displayH + 'px';

  const ctx = canvas.getContext('2d');
  ctx.scale(dpr, dpr);
  const W = displayW;
  const H = displayH;

  // pyramide.fdf height map
  const map = [
    [0, 0, 0, 0, 0],
    [0, 5, 5, 5, 0],
    [0, 5,10, 5, 0],
    [0, 5, 5, 5, 0],
    [0, 0, 0, 0, 0],
  ];
  const rows = map.length;
  const cols = map[0].length;
  const maxH = 10;

  function project(x, y, z, ang) {
    const rx = x * Math.cos(ang) + z * Math.sin(ang);
    const rz = -x * Math.sin(ang) + z * Math.cos(ang);
    const cos30 = Math.cos(Math.PI / 6);
    const sin30 = Math.sin(Math.PI / 6);
    return { x: (rx - y) * cos30, y: (rx + y) * sin30 - rz };
  }

  function edgeColor(t) {
    // accent-3 #4effac (78,255,172) → accent #7ce7ff (124,231,255)
    const r = Math.round(78  + (124 - 78)  * t);
    const g = Math.round(255 + (231 - 255) * t);
    const b = Math.round(172 + (255 - 172) * t);
    return { color: `rgb(${r},${g},${b})`, alpha: 0.35 + t * 0.65 };
  }

  function draw(ts) {
    ctx.clearRect(0, 0, W, H);

    const slide = canvas.closest('.slide');
    if (slide && slide.classList.contains('active')) {
      const ang = (ts / 10000) * Math.PI * 2;
      const scale = Math.min(W, H) / 7;
      const cx = W / 2;
      const cy = H / 2 + 14;

      const pts = [];
      for (let r = 0; r < rows; r++) {
        pts[r] = [];
        for (let c = 0; c < cols; c++) {
          const x = c - (cols - 1) / 2;
          const y = r - (rows - 1) / 2;
          const z = (map[r][c] / maxH) * 2.6;
          const p = project(x, y, z, ang);
          pts[r][c] = { sx: cx + p.x * scale, sy: cy + p.y * scale, h: map[r][c] };
        }
      }

      for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
          const p = pts[r][c];

          if (c + 1 < cols) {
            const t = ((p.h + pts[r][c + 1].h) / 2) / maxH;
            const { color, alpha } = edgeColor(t);
            ctx.globalAlpha = alpha;
            ctx.strokeStyle = color;
            ctx.lineWidth = 0.8 + t * 1.5;
            ctx.shadowColor = color;
            ctx.shadowBlur = t > 0 ? 7 : 0;
            ctx.beginPath();
            ctx.moveTo(p.sx, p.sy);
            ctx.lineTo(pts[r][c + 1].sx, pts[r][c + 1].sy);
            ctx.stroke();
          }

          if (r + 1 < rows) {
            const t = ((p.h + pts[r + 1][c].h) / 2) / maxH;
            const { color, alpha } = edgeColor(t);
            ctx.globalAlpha = alpha;
            ctx.strokeStyle = color;
            ctx.lineWidth = 0.8 + t * 1.5;
            ctx.shadowColor = color;
            ctx.shadowBlur = t > 0 ? 7 : 0;
            ctx.beginPath();
            ctx.moveTo(p.sx, p.sy);
            ctx.lineTo(pts[r + 1][c].sx, pts[r + 1][c].sy);
            ctx.stroke();
          }
        }
      }

      ctx.globalAlpha = 1;
      ctx.shadowBlur = 0;
    }

    requestAnimationFrame(draw);
  }

  requestAnimationFrame(draw);
}

initWireframe();
update();
