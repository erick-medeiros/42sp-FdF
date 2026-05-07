const slides = Array.from(document.querySelectorAll('.slide'));
const prevBtn = document.getElementById('prev');
const nextBtn = document.getElementById('next');
const fsBtn = document.getElementById('fullscreen');
const progressBar = document.getElementById('progress-bar');
const currentEl = document.getElementById('current');
const totalEl = document.getElementById('total');
const crumbTitle = document.getElementById('crumb-title');
const sidebarNav = document.getElementById('sidebar-nav');
const sidebar = document.getElementById('sidebar');
const menuToggle = document.getElementById('menu-toggle');

let currentIndex = 0;

const pad = (n) => String(n).padStart(2, '0');

const navItems = slides.map((slide, i) => {
  const btn = document.createElement('button');
  btn.type = 'button';
  btn.className = 'nav-item';
  btn.innerHTML = `<span class="nav-num">${pad(i + 1)}</span><span class="nav-label">${slide.dataset.title || ''}</span>`;
  btn.addEventListener('click', () => {
    goTo(i);
    if (window.innerWidth < 980) sidebar.classList.remove('open');
  });
  sidebarNav.appendChild(btn);
  return btn;
});

totalEl.textContent = pad(slides.length);

const update = () => {
  slides.forEach((s, i) => s.classList.toggle('active', i === currentIndex));
  navItems.forEach((n, i) => n.classList.toggle('active', i === currentIndex));
  currentEl.textContent = pad(currentIndex + 1);
  crumbTitle.textContent = slides[currentIndex].dataset.title || '';
  const pct = slides.length > 1 ? (currentIndex / (slides.length - 1)) * 100 : 100;
  progressBar.style.width = `${pct}%`;
  const active = navItems[currentIndex];
  if (active) active.scrollIntoView({ block: 'nearest', behavior: 'smooth' });
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

menuToggle.addEventListener('click', () => sidebar.classList.toggle('open'));

window.addEventListener('keydown', (e) => {
  if (e.target.tagName === 'INPUT' || e.target.tagName === 'TEXTAREA') return;
  switch (e.key) {
    case 'ArrowRight':
    case 'PageDown':
    case ' ':
      e.preventDefault(); next(); break;
    case 'ArrowLeft':
    case 'PageUp':
      e.preventDefault(); prev(); break;
    case 'Home':
      e.preventDefault(); goTo(0); break;
    case 'End':
      e.preventDefault(); goTo(slides.length - 1); break;
    case 'f':
    case 'F':
      fsBtn.click(); break;
    case 'Escape':
      if (sidebar.classList.contains('open')) sidebar.classList.remove('open');
      break;
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
