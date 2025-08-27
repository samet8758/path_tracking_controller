t = sim.tout;  % Simulink'ten gelen zaman verisi
x_a1 = sim.x_a1 ; 
y_a1 = sim.y_a1 ; 

x_a2 = sim.x_a2 ; 
y_a2 = sim.y_a2 ; 

x_b1 = sim.x_b1 ; 
y_b1 = sim.y_b1 ; 

x_b2 = sim.x_b2 ; 
y_b2 = sim.y_b2 ; 

% Grafik için bir figure oluşturuyoruz
figure;
hold on;
%axis equal;
grid on;


% Hareket eden öğeleri çizebilmek için çizim nesnelerini oluşturuyoruz
%h1 = plot(x1(1), y1(1), 'ko', 'MarkerFaceColor', 'k'); % İlk nokta
%h2 = plot(x2(1), y2(1), 'ro', 'MarkerFaceColor', 'r'); % İkinci nokta

h1 = plot(x_a1(1), y_a1(1), 'ko','MarkerFaceColor','k') ; 
h2 = plot(x_b1(1), y_b1(1), 'ko','MarkerFaceColor','k') ; 

h3 = plot(x_a2(1), y_a2(1), 'ro', 'MarkerFaceColor','r');
h4 = plot(x_b2(1), y_b2(1), 'ro', 'MarkerFaceColor','r') ; 


line1 = plot([x_a1(1) x_b1(1)], [y_a1(1) y_b1(1)], 'k-');   % Bağlantı çizgisi
line2 = plot([x_a2(1) x_b2(1)], [y_a2(1) y_b2(1)], 'r-'); 


v = VideoWriter('simulasyon.avi'); % veya 'simulasyon.mp4'
open(v);
axis([-10 180 -10 180]) ; 
% Animasyonu başlatmak
for i = 2:length(t)
    % Grafik üzerinde güncellemeler
    set(h1, 'XData', x_a1(i), 'YData', y_a1(i));
    set(h2, 'XData', x_b1(i), 'YData', y_b1(i));
    set(h3, 'XData', x_a2(i), 'YData', y_a2(i));
    set(h4, 'XData', x_b2(i), 'YData', y_b2(i));
    set(line1, 'XData', [x_a1(i), x_b1(i)], 'YData', [y_a1(i), y_b1(i)]);
    set(line2, 'XData', [x_a2(i), x_b2(i)], 'YData', [y_a2(i), y_b2(i)]);
    % Grafik yenileme
    drawnow;
    pause(1/200);  % Hareketin daha düzgün görünmesi için kısa bir gecikme
    frame = getframe(gcf);
    writeVideo(v, frame);
end