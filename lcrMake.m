function lcrMake(rebuild)
    if nargin < 1
        rebuild = false;
    end

    filePath = mfilename('fullpath');
    lcrDir = fileparts(filePath);
    
    currentDir = pwd;
    returnToDir = onCleanup(@()cd(currentDir));
    cd(lcrDir);
    
    opts = '';
    opts = [opts ' -I' fullfile(lcrDir, 'api')];
    opts = [opts ' -L' fullfile(lcrDir) ' -llcr'];
    
    if ismac
        opts = [opts ' -f ' fullfile(lcrDir, 'mexopts.10.9.sh')];
    end
    
    sourceFiles = dir(fullfile(lcrDir, '*.cpp'));
    for i = 1:length(sourceFiles)
        source = sourceFiles(i);
        
        [~, name] = fileparts(source.name);
        mexname = [name '.' mexext];
        mexfile = dir(mexname);
        
        if rebuild || isempty(mexfile) || datenum(source.date) > datenum(mexfile.date)
            command = sprintf('mex %s %s', opts, source.name);
            disp(command);

            try
                eval(command);
            catch
                disp(['Error compiling ''' source.name '''']);
            end
        else
            disp([source.name ' is up to date']);
        end
    end
end